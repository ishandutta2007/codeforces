#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template<typename T>
decltype(auto) operator-(const vector<vector<T>> &seq, const pair<int , int> &idx){
    return seq[idx.first][idx.second];
}
template<typename T>
decltype(auto) operator-(vector<vector<T>> &seq, const pair<int , int> &idx){
    return seq[idx.first][idx.second];
}
pair<int, int> operator+(const pair<int, int> &x, const pair<int, int> &y){
    return mp(x.first + y.first, x.second + y.second);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> grid(n, vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char type;
            cin>>type;
            grid[i][j]=(type=='#');
        }
    }
    vector<vector<bool>> southposs(n, vector<bool>(m, 1));
    for(int i=0;i<n;i++){
        bool foundgood=0, foundbad=0;
        for(int j=0;j<m;j++){
            if(grid[i][j]){
                foundgood=1;
            }
            if(foundgood && !grid[i][j]){
                foundbad=1;
            }
            if(foundgood && foundbad){
                southposs[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        bool foundgood=0, foundbad=0;
        for(int j=m-1;j>=0;--j){
            if(grid[i][j]){
                foundgood=1;
            }
            if(foundgood && !grid[i][j]){
                foundbad=1;
            }
            if(foundgood && foundbad){
                southposs[i][j]=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        bool foundgood=0, foundbad=0;
        for(int j=0;j<n;j++){
            if(grid[j][i]){
                foundgood=1;
            }
            if(foundgood && !grid[j][i]){
                foundbad=1;
            }
            if(foundgood && foundbad){
                southposs[j][i]=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        bool foundgood=0, foundbad=0;
        for(int j=n-1;j>=0;--j){
            if(grid[j][i]){
                foundgood=1;
            }
            if(foundgood && !grid[j][i]){
                foundbad=1;
            }
            if(foundgood && foundbad){
                southposs[j][i]=0;
            }
        }
    }
    vector<vector<int>> prefixrow(n, vector<int>(m+1, 0));
    vector<vector<int>> prefixcol(n+1, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prefixrow[i][j+1]=prefixrow[i][j]+southposs[i][j];
            prefixcol[i+1][j]=prefixcol[i][j]+southposs[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(prefixrow[i][m]==0){
            cout<<"-1\n";
            return;
        }
    }
    for(int i=0;i<m;i++){
        if(prefixcol[n][i]==0){
            cout<<"-1\n";
            return;
        }
    }
    auto valid=[&](const pair<int, int> &x){
        return x.first<n && x.first>=0 && x.second>=0 && x.second<m;
    };
    auto check=[&](const pair<int, int> a, const pair<int, int> &b){
        int x=a.first, x2=b.first, y=a.second, y2=b.second;
        if(x!=x2){
            if(x2>x){
                return ((prefixcol[n][y]-prefixcol[x][y])>0);
            }
            else{
                return (prefixcol[x][y]>0);
            }
        }
        if(y!=y2){
            if(y2>y){
                return ((prefixrow[x][m]-prefixrow[x][y])>0);
            }
            else{
                return (prefixrow[x][y]>0);
            }
        }
        return false;
    };
    vector<pair<int, int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<bool>> found(n, vector<bool>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] && !found[i][j]){
                ++ans;
                found[i][j]=1;
                queue<pair<int, int>> q;
                q.push(mp(i,j));
                while(!q.empty()){
                    for(const auto &path : dir){
                        auto next=q.front()+path;
                        if(valid(next) && grid-next && !(found-next) && check(q.front(), next)){
                            found-next=1;
                            q.push(next);
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}