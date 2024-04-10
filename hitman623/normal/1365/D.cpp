#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m;
string s[55];
pii p[55][55];
pii fp(int x,int y){
    if(p[x][y]==make_pair(x,y)) return {x,y};
    else return p[x][y]=fp(p[x][y].x,p[x][y].y);
}
void merge(int x,int y,int u,int v){
    pii xy=fp(x,y);
    x=xy.x;
    y=xy.y;
    pii uv=fp(u,v);
    p[x][y]=uv;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        rep(j,0,m){
            p[i][j]={i,j};
            if(s[i][j]=='B'){
                if(i){
                    if(s[i-1][j]=='G'){
                        cout<<"No"<<endl;
                        return;
                    }
                    else if(s[i-1][j]=='.') s[i-1][j]='#';
                }
                if(j){
                    if(s[i][j-1]=='G'){
                        cout<<"No"<<endl;
                        return;
                    }
                    else if(s[i][j-1]=='.') s[i][j-1]='#';
                }
                if(i+1<n){
                    if(s[i+1][j]=='G'){
                        cout<<"No"<<endl;
                        return;
                    }
                    else if(s[i+1][j]=='.') s[i+1][j]='#';
                }
                if(j+1<m){
                    if(s[i][j+1]=='G'){
                        cout<<"No"<<endl;
                        return;
                    }
                    else if(s[i][j+1]=='.') s[i][j+1]='#';
                }
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='#') continue;
            if(i and s[i-1][j]!='#') merge(i-1,j,i,j);
            if(j and s[i][j-1]!='#') merge(i,j-1,i,j);
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='G' and fp(i,j)!=fp(n-1,m-1)){
                cout<<"No"<<endl;
                return;
            }
            if(s[i][j]=='B' and fp(i,j)==fp(n-1,m-1)){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}