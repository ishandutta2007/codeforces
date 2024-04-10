#include <stdio.h>
#include <algorithm>

using namespace std;

int n, s, inp;
int c[10];
int best = -1;
int b3,b4,b5;

struct bezout { long long d,a,b;};
bezout extgcd(long long x, long long y) {
    if (y == 0) return (bezout){x,1,0};
    bezout s = extgcd(y, x%y);
    return (bezout){s.d, s.b, s.a-x/y*s.b};
}

void check(int k3, int k4, int k5) {
    int a = k3*c[3], b = k4*c[4], z = k5*c[5];
    if (a+b+z != s) return;
    if (k3 < 0 || k3 > k4 || k4 > k5 || k3 > k5) return;
    
    int ct = abs(a-b) + abs(z-b);
    if (best == -1 || best > ct) {
        best = ct; b3=k3; b4=k4; b5=k5;
    }
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp);
        c[inp]++;
    }    

    for (int k4 = 0; c[4]*k4 <= s; k4++) {
        int C = s - c[4]*k4;
        bezout t = extgcd(c[3],c[5]);
        if (C % t.d != 0) continue;
        
        long long k3 = t.a * C/t.d;
        long long k5 = t.b * C/t.d;
        
        int lcm = c[3]*c[5] / t.d;
        int inc3 = lcm / c[3], inc5 = lcm / c[5];
        
        if (k3 >= 0) {
            int mod = k3/inc3;
            k3 = k3 % inc3;
            k5 = k5 + mod*inc5;
        }
        if (k3 < 0) {
            int mod = -k3/inc3;
            if ((-k3) % inc3 != 0) mod++;
            k3 = k3 + inc3*mod;
            k5 = k5 - inc5*mod;
        }
 
        check(k3,k4,k5);
        
        int st = 0, ed = s;
        while (st < ed) {
            int m = (st+ed+1)/2;
            int nk5 = k5 - m*inc5;
            if (k3 + m*inc3 <= k4 && nk5 >= k4 && c[5]*nk5 >= c[4]*k4) st=m;
            else ed = m-1;
        }
        
        int maxk3 = k3 + inc3*st;
        int maxk5 = k5 - inc5*st;
        check(maxk3, k4, maxk5);
        check(maxk3+inc3, k4, maxk5-inc5);
    }
    
    if (best == -1) printf("%d\n", best);
    else printf("%d %d %d\n", b3, b4, b5);
}