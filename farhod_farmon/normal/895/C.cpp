#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 1000010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

int n;
int a[(1 << 19)];
int b[(1 << 19)];
int c[(1 << 19)];
int p[N];
vector < int > v;

void solve()
{
        for(int i = 2; i <= 70; i++){
                int cnt = 0;
                for(int j = 1; j <= i; j++){
                        cnt += (i % j == 0);
                }
                if(cnt == 2){
                        v.push_back(i);
                }
        }
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, s = 0;
                cin >> x;
                for(int j = 0; j < v.size(); j++){
                        int cnt = 0;
                        while(x % v[j] == 0){
                                x /= v[j];
                                cnt++;
                        }
                        if(cnt % 2){
                                s += (1 << j);
                        }
                }
                c[s]++;
        }
        p[0] = 1;
        for(int i = 1; i < N; i++){
                p[i] = (p[i - 1] + p[i - 1]) % mod;
        }
        for(int i = 0; i < (1 << 19); i++){
                if(!c[i]){
                        continue;
                }
                b[0] = (a[0] + a[i]) % mod;
                b[i] = (a[0] + a[i] + 1) % mod;
                for(int j = 0; j < c[i] - 1; j++){
                        int f = (b[0] + b[i]) % mod;
                        b[0] = f;
                        b[i] = (f + 1) % mod;
                }
                for(int x = 1; x < (1 << 19); x++){
                        int y = x ^ i;
                        if(y < x){
                                continue;
                        }
                        int f = (a[x] + a[y]) % mod;
                        b[x] = 1ll * p[c[i] - 1] * f % mod;
                        b[y] = 1ll * p[c[i] - 1] * f % mod;
                }
                for(int x = 0; x < (1 << 19); x++){
                        a[x] = b[x];
                        b[x] = 0;
                }
        }
        cout << a[0] << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("park.in");
        //fout("park.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}