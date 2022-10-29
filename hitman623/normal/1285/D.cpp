#include <bits/stdc++.h>

#define int         long long
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
int n,a[100005];
int trie[10000006][2],f[10000006],node=1,bits=30;
void add(int x){
    int cur=1,cnt=0;
    while(cnt<=bits){
        int b=(x>>(bits-cnt))&1;
        if(trie[cur][b]){
            cur=trie[cur][b];
            f[cur]++;
        }
        else{
            trie[cur][b]=++node;
            cur=node;
            f[cur]++;
        }
        cnt++;
    }
}
int dfs(int nod,int pos){
	if(trie[nod][0]+trie[nod][1]==0) return 0;
	if(trie[nod][0]==0) return dfs(trie[nod][1],pos-1);
	if(trie[nod][1]==0) return dfs(trie[nod][0],pos-1);
	return min(dfs(trie[nod][0],pos-1),dfs(trie[nod][1],pos-1))|(1<<pos);
}
void solve(){
    cin>>n;
    rep(i,0,n){
    	int x;
    	cin>>x;
    	add(x);
    }
    cout<<dfs(1,30)<<endl;
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