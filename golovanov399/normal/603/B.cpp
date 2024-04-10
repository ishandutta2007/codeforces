#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int mod = 1000000007;

long long pw(long long a, long long b){
    long long res = 1;
    while (b){
        if (b & 1ll)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main(){

    int p = nxt(), k = nxt();
    if (k == 0){
        printf("%d\n", (int)pw(p, p - 1));
        return 0;
    }
    if (k == 1){
        printf("%d\n", (int)pw(p, p));
        return 0;
    }
    long long qw = 1;
    int d = 0;
    do {
        qw = qw * k % p;
        d++;
    } while (qw != 1);
    printf("%d\n", (int)pw(p, (p - 1) / d));

    return 0;
}