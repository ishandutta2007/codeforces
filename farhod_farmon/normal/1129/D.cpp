#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 100100;
const int Q = 250200;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int d[N];
int f[N];
int l[N];
int p[N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
        else if(x < 0){
                x += mod;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        int s = 1, x, h;
        d[0] = 1;
        for(int i = 1; i <= n; i++){
                cin >> x;
                for(int j = l[x] + 1; j <= i; j++){
                        if(f[j] == k){
                                s -= d[j - 1];
                                if(s < 0){
                                        s += mod;
                                }
                        }
                        f[j] += 1;
                }
                h = p[x];
                for(int j = l[x]; j > h; j--){
                        f[j] -= 1;
                        if(f[j] == k){
                                s += d[j - 1];
                                if(s >= mod){
                                        s -= mod;
                                }
                        }
                }
                p[x] = l[x];
                l[x] = i;
                d[i] = s;
                add(s, s);
        }
        cout << d[n] << "\n";
}