#include <stdio.h>
#include <vector>
#include <map>

int n, L, R, q, x;
int a[110000];
std::vector<int> breakpoints[2];
std::map<int, long long> gcdmap;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int cur_index = 0;
    for (int i = n-1; i >= 0; i--) {
        breakpoints[cur_index^1].clear();
        breakpoints[cur_index^1].push_back(i);
        
        int cur_gcd = a[i];
        for (int j = 0; j < (int)breakpoints[cur_index].size(); j++) {
            int this_bp = breakpoints[cur_index][j];
            if (gcd(cur_gcd, a[this_bp]) != cur_gcd) {
                gcdmap[cur_gcd] += this_bp - *breakpoints[cur_index^1].rbegin();
                breakpoints[cur_index^1].push_back(this_bp);
                cur_gcd = gcd(cur_gcd, a[this_bp]);
            }
        }       

        gcdmap[cur_gcd] += n - *breakpoints[cur_index^1].rbegin();
        cur_index ^= 1;
    }

    for (scanf("%d", &q); q; q--) {
        scanf("%d", &x);
        printf("%lld\n", gcdmap[x]);
    }
}