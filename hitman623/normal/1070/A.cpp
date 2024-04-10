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
int d,s;
int vis[505][5005];
pii par[505][5005];
int digit[505][5005];
void solve(){
    cin>>d>>s;
    queue<pii> q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        auto g=q.front();
        q.pop();
        if(g==make_pair(0,s)){
            string ans;
            pii cur={0,s};
            while(cur!=make_pair(0,0)){
                ans+=digit[cur.x][cur.y]+'0';
                cur=par[cur.x][cur.y];
            }
            reverse(all(ans));
            cout<<ans<<endl;
            return;
        }
        rep(i,0,10){
            int D=(g.x*10+i)%d;
            int S=g.y+i;
            if(vis[D][S] or S>s) continue;
            par[D][S]=g;
            digit[D][S]=i;
            vis[D][S]=1;
            q.push({D,S});
        }
    }
    cout<<-1<<endl;
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