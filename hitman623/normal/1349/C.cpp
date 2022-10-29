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
int n,m,q,d[1001][1001];
bool vis[1001][1001];
string s[1001];
vii w;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve(){
    cin>>n>>m>>q;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
    	rep(j,0,m){
    		int f=0;
    		if(i and s[i][j]==s[i-1][j]) f=1;
    		if(j and s[i][j]==s[i][j-1]) f=1;
    		if(i+1<n and s[i][j]==s[i+1][j]) f=1;
    		if(j+1<m and s[i][j]==s[i][j+1]) f=1;
    		if(f){
    			w.pb({i,j});
    			d[i][j]=0;
    			vis[i][j]=1;
    		}
    	}
    }
    int dis=0;
    while(1){
    	dis++;
    	vii ww;
    	rep(_,0,sz(w)){
    		int i=w[_].x;
    		int j=w[_].y;
    		rep(k,0,4){
	    		if(i+dx[k]>=0 and i+dx[k]<n and j+dy[k]>=0 and j+dy[k]<m and vis[i+dx[k]][j+dy[k]]==0){
	    			vis[i+dx[k]][j+dy[k]]=1;
	    			d[i+dx[k]][j+dy[k]]=dis;
	    			ww.pb({i+dx[k],j+dy[k]});
	    		}
    		}
    	}
		if(sz(ww)==0) break;
		swap(w,ww);
    }
    while(q--){
    	int x,y;
    	ll p;
    	cin>>x>>y>>p;
    	x--;
    	y--;
    	if(vis[x][y]==0 or d[x][y]>=p) cout<<s[x][y]<<endl;
    	else{
    		p-=d[x][y];
    		cout<<(char)((s[x][y]-'0'+p%2)%2+'0')<<endl;
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