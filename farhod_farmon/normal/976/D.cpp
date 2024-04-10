#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int a[N];
bool used[N][N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < int > v;
        for(int i = 1; i <= a[n] + 1; i++){
                v.push_back(i);
        }
        for(int i = n, j = 1, g = 0; i >= j; i--){
                if(i == j){
                        for(int j = 0; j <= a[i] - g; j++){
                                for(int h = j + 1; h <= a[i] - g; h++){
                                        used[v[j]][v[h]] = 1;
                                        used[v[h]][v[j]] = 1;
                                }
                        }
                        break;
                }
                while(v.size() > a[i - 1] - g + 1){
                        for(int j = 0; j < v.size() - 1; j++){
                                used[v[j]][v.back()] = 1;
                                used[v.back()][v[j]] = 1;
                        }
                        g++;
                        v.pop_back();
                        if(a[j] == g){
                                if(j + 1 == i){
                                        break;
                                }
                                while(v.size() > a[i - 1] - g + 1){
                                        v.pop_back();
                                }
                                j++;
                        }
                }
        }
        vector < pair < int, int > > ans;
        for(int i = 1; i <= a[n] + 1; i++){
                for(int j = i + 1; j <= a[n] + 1; j++){
                        if(used[i][j]){
                                ans.push_back({i, j});
                        }
                }
        }
        cout << ans.size() << "\n";
        for(auto p: ans){
                cout << p.fi << " " << p.se << "\n";
        }
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