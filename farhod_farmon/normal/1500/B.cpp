#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 1000500;

long long n, m;
long long k, L;
long long A[N], B[N];
long long st[N];

long long gcd(long long a, long long b, long long &x, long long &y){
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool good(long long m)
{
        long long cnt = m;
        for(int i = 1; i < N; i++){
                if(st[i] && st[i] <= m){
                        cnt -= (m - st[i]) / L + 1;
                }
        }
        return cnt >= k;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                A[x] = i;
        }
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x;
                B[x] = i;
        }

        long long x, y;
        long long g = gcd(n, m, x, y);
        L = n * m / g;

        for(int i = 1; i < N; i++){
                if(A[i] && B[i] && (B[i] - A[i]) % g == 0){
                        st[i] = (B[i] - A[i]) / g * x % L;
                        st[i] = A[i] + n * st[i];
                        st[i] = st[i] % L;
                        if(st[i] <= 0){
                                st[i] += L;
                        }
                }
        }

        long long l = 1, r = 4e18;
        while(l < r){
                long long m = (l + r) / 2;
                if(!good(m)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }

        cout << l << "\n";
}