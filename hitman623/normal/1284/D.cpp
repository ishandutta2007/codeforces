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
int n;
vii v[2];
vi coords;
set<pii> st,en;
map<int,vi> opened,closed;
void go(int f){
	rep(i,0,n){
		opened[v[f][i].x].pb(i);
		closed[v[f][i].y].pb(i);
		coords.pb(v[f][i].x);
		coords.pb(v[f][i].y);
		st.insert({v[1^f][i].x,i});
		en.insert({v[1^f][i].y,i});
	}
	sort(all(coords));
	coords.resize(unique(all(coords))-coords.begin());
	for(auto i:coords){
		for(auto j:opened[i]){
			en.erase({v[1^f][j].y,j});
			st.erase({v[1^f][j].x,j});
		}
		for(auto j:closed[i]){
			int l=v[1^f][j].x;
			int r=v[1^f][j].y;
			auto it=st.lower_bound({l,-1});
			if(it!=st.end() and (*it).x<=r){
				cout<<"NO"<<endl;
				exit(0);
			}
			it=en.upper_bound({r,hell});
			if(it!=en.begin()){
				it--;
				if((*it).x>=l){
					cout<<"NO"<<endl;
					exit(0);
				}
			}
		}
	}
}
void solve(){
	cin>>n;
	v[0].resize(n);
	v[1].resize(n);
	rep(i,0,n){
		int x,y,u,V;
		cin>>x>>y>>u>>V;
		v[0][i]={x,y};
		v[1][i]={u,V};
	}
	go(0);
	opened.clear();
	closed.clear();
	coords.clear();
	st.clear();
	en.clear();
	go(1);
	cout<<"YES"<<endl;
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