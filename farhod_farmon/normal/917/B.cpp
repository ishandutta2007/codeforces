#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int m;
int d[N][N][26];
vector < pair < int, char > > v[N];

int f(int x, int y, char last)
{
        int &ans = d[x][y][last - 'a'];
        if(ans){
                return ans;
        }
        ans = 2;
        for(auto p: v[x]){
                int z = p.fi;
                char c = p.se;
                if(c < last){
                        continue;
                }
                if(f(y, z, c) == 2){
                        ans = 1;
                }
        }
        return ans;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                char c;
                cin >> x >> y >> c;
                v[x].push_back({y, c});
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(f(i, j, 'a') == 1){
                                cout << 'A';
                        }
                        else{
                                cout << 'B';
                        }
                }
                cout << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}