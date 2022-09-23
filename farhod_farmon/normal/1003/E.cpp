#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int d;
int k;
int G;
int v[N];
vector < pair < int, int > > ans;

void add(int x, int y)
{
        ans.push_back({x, y});
        v[x]++;
        v[y]++;
}

void go(int x, int deep)
{
        if(!deep){
                return;
        }
        while(G < n && v[x] < k){
                G++;
                add(x, G);
                go(G, deep - 1);
        }
}

void solve()
{
        cin >> n >> d >> k;
        d = d + 1;
        if(d > n){
                cout << "NO" << "\n";
                return;
        }
        for(int i = 1; i < d; i++){
                add(i, i + 1);
        }
        G = d;
        for(int i = 1; i <= d; i++){
                int g = min(i - 1, d - i);
                go(i, g);
        }
        if(G < n){
                cout << "NO" << "\n";
                return;
        }
        for(int i = 1; i <= n; i++){
                if(v[i] > k){
                        cout << "NO" << "\n";
                        return;
                }
        }
        cout << "YES" << "\n";
        for(auto p: ans){
                cout << p.fi << " " << p.se << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}