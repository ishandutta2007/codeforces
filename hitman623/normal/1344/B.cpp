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
int n,m,row[1002],col[1002];
pii par[1001][1001];
string s[1002];
pii fp(int x,int y){
	if(par[x][y].x==x and par[x][y].y==y) return par[x][y];
	else return par[x][y]=fp(par[x][y].x,par[x][y].y);
}
void merge(pii lhs,pii rhs){
	lhs=fp(lhs.x,lhs.y);
	rhs=fp(rhs.x,rhs.y);
	par[lhs.x][lhs.y]=rhs;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
    	rep(j,0,m){
    		par[i][j]={i,j};
    	}
    }
    rep(i,0,n){
    	rep(j,0,m){
    		if(s[i][j]=='.') continue;
    		if(i and s[i-1][j]=='#') merge({i,j},{i-1,j});
    		if(j and s[i][j-1]=='#') merge({i,j},{i,j-1});
    	}
    }
    rep(i,0,n){
    	vii v;
    	int l=-1;
    	rep(j,0,m){
    		if(s[i][j]=='#'){
    			if(l==-1) l=j;
    		}
    		else if(l!=-1){
    			v.pb({l,j-1});
    			l=-1;
    		}
    	}
    	if(l!=-1) v.pb({l,m-1});
    	if(sz(v)>1){
    		cout<<-1<<endl;
    		return;
    	}
    }
    rep(j,0,m){
    	vii v;
    	int l=-1;
    	rep(i,0,n){
    		if(s[i][j]=='#'){
    			if(l==-1) l=i;
    		}
    		else if(l!=-1){
    			v.pb({l,i-1});
    			l=-1;
    		}
    	}
    	if(l!=-1) v.pb({l,n-1});
    	if(sz(v)>1){
    		cout<<-1<<endl;
    		return;
    	}
    }
    set<pii> st;
    rep(i,0,n){
    	rep(j,0,m){
    		if(s[i][j]=='.') continue;
    		st.insert({fp(i,j)});
    		row[i]=1;
    		col[j]=1;
    	}
    }
    int r=0,c=0;
    rep(i,0,n) if(row[i]==0) r++;
    rep(i,0,m) if(col[i]==0) c++;
    if(r+c and min(r,c)==0){
    	cout<<-1<<endl;
    	return;
    }
    cout<<sz(st)<<endl;
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