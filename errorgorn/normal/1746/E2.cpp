//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int NQ=0;

bool ask(vector<int> v){
	NQ++;
	cout<<"? "<<sz(v)<<" "; for (auto it:v) cout<<it<<" "; cout<<endl;
	string s;
	cin>>s;
	return s=="YES";
}

int memo[10][10];
ii bt[10][10];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	
	rep(x,0,10) rep(y,0,10){
		if (x+y<=2) memo[x][y]=0,bt[x][y]=ii(-1,-1);
		else memo[x][y]=1e9;
	}
	
	rep(zzz,0,1000){
		rep(x,0,10) rep(y,0,10) if (2<x+y && x+y<10){
			ii config={-1,-1}; int best=1e9;
			rep(i,0,x+1) rep(j,0,y+1){
				ii a={i+j,x-i};
				ii b={x+y-i-j,i};
				int res=max(memo[a.fi][a.se],memo[b.fi][b.se])+1;
				if (res<best) best=res,config={i,j};
			}
			memo[x][y]=best;
			bt[x][y]=config;
		}
	}
	
	int n; cin>>n;
	vector<int> a,b;
	rep(x,1,n+1) a.pub(x);
	
	while (sz(a)+sz(b)>=3){
		int sa=sz(a)/2,sb=(sz(b)+1)/2;
		if (sz(a)+sz(b)<10) tie(sa,sb)=bt[sz(a)][sz(b)];
		vector<int> v;
		rep(x,0,sa) v.pub(a[x]);
		rep(x,0,sb) v.pub(b[x]);
		
		vector<int> ta,tb;
		if (ask(v)){
			rep(x,0,sa) ta.pub(a[x]);
			rep(x,sa,sz(a)) tb.pub(a[x]);
			rep(x,0,sb) ta.pub(b[x]);
		}
		else{
			rep(x,sa,sz(a)) ta.pub(a[x]);
			rep(x,0,sa) tb.pub(a[x]);		
			rep(x,sb,sz(b)) ta.pub(b[x]);
		}
		
		a=ta,b=tb;
	}
	
	vector<int> v;
	for (auto it:a) v.pub(it);
	for (auto it:b) v.pub(it);
	
	for (auto it:v){
		cout<<"! "<<it<<endl;
		string s;
		cin>>s;
		if (s==":)") break;
	}
}