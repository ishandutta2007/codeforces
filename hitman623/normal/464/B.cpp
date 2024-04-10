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
int p[8][3];
int x[8],y[8],z[8],X[8],Y[8],Z[8];
void sol(int in){
	if(in==8){
		set<pair<int,pii>> st;
		rep(i,0,8){
			X[i]=x[i]-x[0];
			Y[i]=y[i]-y[0];
			Z[i]=z[i]-z[0];
			st.insert({X[i],{Y[i],Z[i]}});
		}
		if(sz(st)!=8) return;
		int d=1e18;
		rep(i,1,8){
			d=min(d,X[i]*X[i]+Y[i]*Y[i]+Z[i]*Z[i]);
		}
		vi g;
		rep(i,1,8){
			if(X[i]*X[i]+Y[i]*Y[i]+Z[i]*Z[i]==d) g.pb(i);
		}
		if(sz(g)!=3) return;
		for(auto i:g){
			for(auto j:g){
				if(i!=j and X[i]*X[j]+Y[i]*Y[j]+Z[i]*Z[j]!=0) return;
			}
		}
		rep(i,0,8){
			int curx=X[g[0]]*(i>>2)+X[g[1]]*((i>>1)&1)+X[g[2]]*(i&1);
			int cury=Y[g[0]]*(i>>2)+Y[g[1]]*((i>>1)&1)+Y[g[2]]*(i&1);
			int curz=Z[g[0]]*(i>>2)+Z[g[1]]*((i>>1)&1)+Z[g[2]]*(i&1);
			if(st.count({curx,{cury,curz}})){
				st.erase({curx,{cury,curz}});
				continue;
			}
			return;
		}
		cout<<"YES"<<endl;
		rep(i,0,8){
			cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
		}
		exit(0);
	}
	vi v={0,1,2};
	do{
		x[in]=p[in][v[0]];
		y[in]=p[in][v[1]];
		z[in]=p[in][v[2]];
		sol(in+1);
	}while(in and next_permutation(all(v)));
}
void solve(){
	rep(i,0,8){
		rep(j,0,3){
			cin>>p[i][j];
		}
	}
	sol(0);
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