#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1000200;
const int mod = 998244353;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int d[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        for(int i = 1; i < N; i++){
                for(int j = i; j < N; j += i){
                        d[j] += 1;
                }
        }
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; i++){
                add(d[i], sum);
                add(sum, d[i]);
        }
        cout << d[n] << "\n";
}