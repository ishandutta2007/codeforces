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

const int N = 1505;

int n, m;
int c[N];
int col[N];
bool shit[N];
vector < int > a[N], b[N];
map < vector < int >, vector < int > > id;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 0; i < n; i++){
                a[i].resize(m);
                for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 0; i < n; i++){
                b[i].resize(m);
                for(int j = 0; j < m; j++){
                        cin >> b[i][j];
                }
        }
        for(int i = n - 1; i >= 0; i--){
                id[b[i]].push_back(i);
        }

        for(int i = 0; i < n; i++){
                if(id[a[i]].empty()){
                        cout << -1 << "\n";
                        return 0;
                }
                c[id[a[i]].back()] = i;
                id[a[i]].pop_back();
                shit[i] = true;
        }

        vector < int > res;
        for(int j = 0; j < m; j++){
                for(int i = 0; i < n - 1; i++){
                        col[j] += (a[c[i]][j] > a[c[i + 1]][j]);
                }
                if(!col[j]){
                        res.push_back(j);
                        col[j] = -1;
                }
        }
        for(int h = 0; h < res.size(); h++){
                int j = res[h];

                for(int i = 0; i < n - 1; i++){
                        if(!shit[i] || a[c[i]][j] >= a[c[i + 1]][j]){
                                continue;
                        }
                        shit[i] = false;
                        for(int k = 0; k < m; k++){
                                if(col[k] == -1){
                                        continue;
                                }
                                col[k] -= a[c[i]][k] > a[c[i + 1]][k];
                                if(col[k] == 0){
                                        res.push_back(k);
                                        col[k] = -1;
                                }
                        }
                }
        }

        int bs = false;
        for(int i = 0; i < n - 1; i++){
                if(shit[i] && c[i] > c[i + 1]){
                        bs = true;
                }
        }
        if(bs){
                cout << -1 << "\n";
                return 0;
        }
        reverse(res.begin(), res.end());
        cout << res.size() << "\n";
        for(int x: res){
                cout << x + 1 << " ";
        }
}