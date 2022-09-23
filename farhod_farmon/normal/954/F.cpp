#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100010;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

vector < vector < long long > > mult(vector < vector < long long > > x, vector < vector < long long > > y)
{
        vector < vector < long long > > v(4);
        for(int i = 0; i <= 3; i++){
                v[0].push_back(0);
        }
        for(int i = 1; i <= 3; i++){
                v[i].push_back(0);
                for(int j = 1; j <= 3; j++){
                        v[i].push_back(0);
                        for(int h = 1; h <= 3; h++){
                                v[i][j] = (v[i][j] + x[i][h] * y[h][j]) % mod;
                        }
                }
        }
        return v;
}

vector < vector < long long > > pw(vector < vector < long long > > x, long long g)
{
        if(g == 1){
                return x;
        }
        if(g % 2){
                return mult(x, pw(x, g - 1));
        }
        else{
                return pw(mult(x, x), g / 2);
        }
}

int n;
long long A[N], L[N], R[N];
long long m;
map < long long, int > id;

void solve()
{
        cin >> n >> m;
        vector < long long > v;
        for(int i = 1; i <= n; i++){
                cin >> A[i] >> L[i] >> R[i];
                v.push_back(L[i] - 1);
                v.push_back(R[i]);
        }
        v.push_back(1);
        v.push_back(m);
        sort(v.begin(), v.end());
        vector < long long > nv;
        for(int i = 0; i < v.size(); i++){
                if(i + 1 < v.size() && v[i] == v[i + 1]){
                        continue;
                }
                nv.push_back(v[i]);
        }v = nv;
        for(int i = 0; i < v.size(); i++){
                id[v[i]] = i;
        }
        vector < int > g[4];
        g[1].resize(v.size(), 0);
        g[2].resize(v.size(), 0);
        g[3].resize(v.size(), 0);
        for(int i = 1; i <= n; i++){
                g[A[i]][id[L[i] - 1] + 1]++;
                g[A[i]][id[R[i]] + 1]--;
        }
        vector < long long > d = {0, 0, 1, 0};
        for(int i = 1; i < v.size(); i++){
                g[1][i] += g[1][i - 1];
                g[2][i] += g[2][i - 1];
                g[3][i] += g[3][i - 1];
                vector < vector < long long > > ma(4);
                for(int i = 0; i <= 3; i++){
                        for(int j = 0; j <= 3; j++){
                                ma[i].push_back(0);
                        }
                }
                if(g[1][i] == 0){
                        ma[1][1] = ma[1][2] = 1;
                }
                if(g[2][i] == 0){
                        ma[2][1] = ma[2][2] = ma[2][3] = 1;
                }
                if(g[3][i] == 0){
                        ma[3][2] = ma[3][3] = 1;
                }
                ma = pw(ma, v[i] - v[i - 1]);
                vector < long long > nd = {0, 0, 0, 0};
                for(int j = 1; j <= 3; j++){
                        for(int h = 1; h <= 3; h++){
                                nd[j] = (nd[j] + ma[j][h] * d[h]) % mod;
                        }
                }
                d = nd;
        }
        cout << d[2] << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}