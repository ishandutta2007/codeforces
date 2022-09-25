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

int n;
int mask[1005];

set<int> ask(set<int> v,int val){
	vector<int> qu(n,0);
	for (auto it:v) qu[it-1]=val;
	cout<<"? "; rep(x,0,n) cout<<min(qu[x],n-1)<<" "; cout<<endl;
	string s;
	cin>>s;
	
	set<int> res;
	rep(x,0,n) if (s[x]=='1') res.insert(x+1);
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	vector<set<int> > head={{1}};
    vector<set<int> > body{{}};
    
    rep(x,2,n+1) body[0].insert(x);
    
    int curr=512;
    while (curr>=2){
		set<int> small;
		set<int> big1,big2;
		
		rep(x,0,sz(head)){
			for (auto it:head[x]) small.insert(it);
			
			if (x%2==0) for (auto it:head[x]) big1.insert(it);
			else for (auto it:head[x]) big2.insert(it);
		}
		
		small=ask(small,curr-1);
		big1=ask(big1,curr);
		big2=ask(big2,curr);
		
		vector<set<int> > head2;
		vector<set<int> > body2;
		rep(x,0,sz(head)){
			set<int> h0=head[x],h1;
			set<int> b0,b1;
			
			if (x%2) swap(big1,big2);
			
			for (auto it:body[x]){
				if (small.count(it) && big1.count(it)) b0.insert(it);
				else if (big1.count(it)) h1.insert(it);
				else b1.insert(it);
			}
			
			if (x%2) swap(big1,big2);
			
			head2.pub(h0),head2.pub(h1);
			body2.pub(b0),body2.pub(b1);
		}
		
		curr>>=1;
		head=head2;
		body=body2;
		
		//cout<<"head: "<<endl;
		//for (auto x:head){
			//if (!x.empty()){ for (auto y:x) cout<<y<<" "; cout<<endl; }
		//}
		//cout<<endl;
		//cout<<"body: "<<endl;
		//for (auto x:body){
			//if (!x.empty()){ for (auto y:x) cout<<y<<" "; cout<<endl; }
		//}
		//cout<<endl;
	}
	
	vector<vector<int> > layer;
	rep(x,0,sz(head)){
		vector<int> temp;
		for (auto it:head[x]) temp.pub(it);
		if (!temp.empty()) layer.pub(temp);
		
		temp.clear();
		for (auto it:body[x]) temp.pub(it);
		if (!temp.empty()) layer.pub(temp);
	}
	
	//rep(x,0,sz(layer)){
		//for (auto it:layer[x]) cout<<it<<" "; cout<<endl;
	//}
	
	vector<int> res;
	rep(resid,0,3){
		memset(mask,0,sizeof(mask));
		set<int> s[10];
		
		for (int x=resid;x<sz(layer);x+=3){
			rep(y,0,sz(layer[x])){
				rep(bit,0,10) if (y&(1<<bit)) s[bit].insert(layer[x][y]);
			}
		}
		
		rep(x,0,10) s[x]=ask(s[x],1);
		rep(x,0,10) for (auto it:s[x]) mask[it]|=1<<x;
		
		for (int x=resid+1;x<sz(layer);x+=3){
			for (auto it:layer[x]){
				res.pub(layer[x-1][mask[it]]);
				res.pub(it);
			}
		}
	}
	
	cout<<"! ";
	rep(x,0,n-1) cout<<res[2*x]<<" "<<res[2*x+1]<<endl;
}