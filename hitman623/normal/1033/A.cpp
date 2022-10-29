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
int n,ax,ay,bx,by,cx,cy,vis[1001][1001];
void dfs(int x,int y){
    if(x<1 or x>n or y<1 or y>n or vis[x][y] or x==ax || y==ay || abs(x-ax)==abs(y-ay)) return;
    vis[x][y]=1;
    if(x==cx and y==cy){
        cout<<"YES"<<endl;
        exit(0);
    }
    rep(i,-1,2){
        rep(j,-1,2){
            if(i==0 and j==0) continue;
            dfs(x+i,y+j);
        }
    }
}
void solve(){
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    dfs(bx,by);
    cout<<"NO"<<endl;
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