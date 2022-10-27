#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

char a[1005][1005];
int row[1005][1005];
int col[1005][1005];

char dir[100005];
int len[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);
    int n, m;
    cin>>n>>m;
    vector<pair<char, pair<int,int> > > start;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
            if(a[i][j] <= 'Z' && a[i][j] >= 'A'){
                start.push_back({a[i][j], {i, j}});
                a[i][j] = '.';
            }
        }
    }
    for(int i = 1; i <= n; i++){
        row[i][0] = 0;
        for(int j = 1; j <= m; j++){
            row[i][j] = row[i][j-1];
            if(a[i][j] == '#')row[i][j]++;
        }
    }
    for(int j = 1; j <= m; j++){
        col[0][j] = 0;
        for(int i = 1; i <= n; i++){
            col[i][j] = col[i-1][j];
            if(a[i][j] == '#')col[i][j]++;
        }
    }
    int k;
    cin>>k;
    for(int i = 1; i <= k; i++){
        cin>>dir[i]>>len[i];
    }
    sort(start.begin(), start.end());
    string ans = "";
    for(auto st : start){
        int x = st.second.first, y = st.second.second;
        bool pos = true;
        for(int i = 1; i <= k; i++){
            if(dir[i] == 'N'){
                if(x <= len[i] || col[x][y] != col[x-len[i]-1][y]){
                    pos = false;
                    break;
                }else{
                    x -= len[i];
                }
            }else if(dir[i] == 'S'){
                if(x + len[i] > n || col[x + len[i]][y] != col[x-1][y]){
                    pos = false;
                    break;
                }else{
                    x += len[i];
                }
            }else if(dir[i] == 'E'){
                if(y + len[i] > m || row[x][y + len[i]] != row[x][y-1]){
                    pos = false;
                    break;
                }else{
                    y += len[i];
                }
            }else{
                if(y <= len[i] || row[x][y] != row[x][y-len[i]-1]){
                    pos = false;
                    break;
                }else{
                    y -= len[i];
                }
            }
        }
        if(pos)ans += st.first;
    }
    if(ans.size() != 0)cout<<ans<<endl;
    else cout<<"no solution"<<endl;
}