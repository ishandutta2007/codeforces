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
#define hell        1000000007
#define R           500
#define C           500
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int kx,ky,x[670],y[670],cnt[2][2];
int vis[1001][1001];
void query(){
    int k,a,b;
    cin>>k>>a>>b;
    if(k<=0) exit(0);
    k--;
    vis[x[k]][y[k]]=0;
    x[k]=a;
    y[k]=b;
    vis[x[k]][y[k]]=1;
}
void move(int dx,int dy){
    kx+=dx;
    ky+=dy;
    if(vis[kx][ky]) kx-=dx;
    cout<<kx<<" "<<ky<<endl;
}
void solve(){
    cin>>kx>>ky;
    rep(i,0,666) cin>>x[i]>>y[i],vis[x[i]][y[i]]=1;  
    while(kx!=R or ky!=C){
        if(kx>R) move(-1,0);
        else if(kx<R) move(1,0);
        else if(ky>C) move(0,-1);
        else if(ky<C) move(0,1);
        query();
    }
    rep(i,0,666) cnt[x[i]<R][y[i]<C]++;
    int mn=hell;
    rep(i,0,2){
        rep(j,0,2){
            mn=min(mn,cnt[i][j]);
        }
    }
    rep(i,0,2){
        rep(j,0,2){
            if(cnt[i][j]==mn){
                while(1){
                    move(i?1:-1,j?1:-1);
                    query();
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}