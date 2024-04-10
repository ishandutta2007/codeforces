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

int m,f[3003][3003],v[3003],w[1<<5],ans;
inline void add(int &x,int y){
    if(x+y>=hell) x=x+y-hell;
    else x=x+y;
}
int trie[9000006][2],node=1;
void go(int pos,int g){
    int cur=1;
    while(pos>=0){
        if(!trie[cur][v[pos]]){
            trie[cur][v[pos]]=++node;
            add(ans,f[pos][g]);
        }
        cur=trie[cur][v[pos]];
        pos--;
    }
}
void solve(){
    cin>>m;
    rep(i,0,m){
        cin>>v[i];
        rep(j,0,i+1){
            rep(k,1,5){
                if(i-k+1>=j and (k<=3 or !w[v[i-k+1]*8+v[i-k+2]*4+v[i-k+3]*2+v[i]])){
                    if(i-k+1==j) add(f[j][i],1);
                    else add(f[j][i],f[j][i-k]);
                }
            }
        }
        go(i,i);
        cout<<ans<<endl;
    }
}

signed main(){
    w[3]=w[5]=w[14]=w[15]=1;
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