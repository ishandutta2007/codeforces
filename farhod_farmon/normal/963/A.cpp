#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 3000100;
const long long mod = 1e9 + 9;
const long long block = sqrt(N);

using namespace std;

long long n, a, b, k;
char c[N];

long long pw(long long x, long long n)
{
        if(n == 0){
                return 1;
        }
        if(n % 2){
                return x * pw(x, n - 1) % mod;
        }
        else{
                return pw(x * x % mod, n / 2);
        }
}

vector < vector < long long > > mult(vector < vector < long long > > x, vector < vector < long long > > y)
{
        vector < vector < long long > > v;
        v.resize(2);
        for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                        v[i].push_back(0);
                        for(int h = 0; h < 2; h++){
                                v[i][j] = (v[i][j] + x[i][h] * y[h][j] % mod) % mod;
                        }
                }
        }
        return v;
}

vector < vector < long long > > po(vector < vector < long long > > v, long long n)
{
        if(n == 1){
                return v;
        }
        if(n % 2){
                return mult(v, po(v, n - 1));
        }
        else{
                return po(mult(v, v), n / 2);
        }
}

void solve()
{
        cin >> n >> a >> b >> k;
        long long m = pw(b, k) * pw(pw(a, k), mod - 2) % mod, A = pw(a, mod - 2), B = b, f = pw(a, n);
        vector < vector < long long > > tv(2);
        tv[0].resize(2); tv[1].resize(2);
        tv[0][0] = 1; tv[0][1] = 0;
        tv[1][0] = tv[1][1] = m;
        long long ans = 0;
        for(int i = 0; i < k; i++){
                cin >> c[i];
                if(c[i] == '+'){
                        ans = (ans + f) % mod;
                }
                else{
                        ans = (ans - f) % mod;
                        if(ans < 0){
                                ans += mod;
                        }
                }
                f = f * A % mod * B % mod;
        }
        vector < vector < long long > > v(2);
        v[0].resize(2); v[1].resize(2);
        v[0][0] = v[0][1] = ans;
        v[1][0] = v[1][1] = 0;
        if((n + 1) / k > 1){
                v = mult(v, po(tv, (n + 1) / k - 1));
        }
        cout << v[0][0] << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}