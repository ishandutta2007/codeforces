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

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int n; cin>>n;
	vector<int> A,B;
	rep(x,1,n+1) A.pub(x);
	
	while (sz(A)+sz(B)>3){
		int sa=sz(A)/2,sb=(sz(B)+1)/2;
		vector<int> v;
		rep(x,0,sa) v.pub(A[x]);
		rep(x,0,sb) v.pub(B[x]);
		
		vector<int> ta,tb;
		if (ask(v)){
			rep(x,0,sa) ta.pub(A[x]);
			rep(x,sa,sz(A)) tb.pub(A[x]);
			rep(x,0,sb) ta.pub(B[x]);
		}
		else{
			rep(x,sa,sz(A)) ta.pub(A[x]);
			rep(x,0,sa) tb.pub(A[x]);		
			rep(x,sb,sz(B)) ta.pub(B[x]);
		}
		
		A=ta,B=tb;
	}
	
	assert(NQ<=52);
	
	vector<int> v;
	for (auto it:B) v.pub(it);
	for (auto it:A) v.pub(it);
	
	if (sz(v)==3){
		bool a;
		if (sz(A)==2 && sz(B)==1) a=false;
		else a=ask({v[0]});
		bool b=ask({v[1]});
		bool c=ask({v[1]});
		bool d=ask({v[2]});
		
		if (a && b) v={v[0],v[1]};
		else if (!a && b) v={v[1],v[2]};
		else if (a && !b) v={v[1],v[2]};
		else{
			if (!c) v={v[0],v[2]};
			else{
				if (d) v={v[1],v[2]};
				else v={v[0],v[1]};
			}
		}
	}
	
	for (auto it:v){
		cout<<"! "<<it<<endl;
		string s;
		cin>>s;
		if (s==":)") break;
	}
}