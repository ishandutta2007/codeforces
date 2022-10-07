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

struct UFDS{
	int p[1005];
	int s[1005];
	
	void clear(){
		rep(x,0,1005){
			p[x]=x;
			s[x]=1;
		}
	}
	
	int par(int i){
		if (p[i]==i) return p[i];
		else return p[i]=par(p[i]);
	}
	
	void unions(int i,int j){
		i=par(i),j=par(j);
		if (i==j) return;
		p[i]=j;
		s[j]+=s[i];
	}
} ufds;

int n;
int arr[1005];

int ask(int u){
	cout<<"? "<<u<<endl;
	int res;
	cin>>res;
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		vector<int> idx;
		rep(x,1,n+1) idx.pub(x);
		
		sort(all(idx),[](int i,int j){
			return arr[i]>arr[j];
		});
		
		ufds.clear();
		for (auto it:idx) if (ufds.s[ufds.par(it)]==1){
			rep(x,0,arr[it]){
				int temp=ask(it);
				
				ufds.unions(temp,it);
				if (ufds.s[ufds.par(it)]!=x+2) break;
			}
		}
		
		cout<<"! "; rep(x,1,n+1) cout<<ufds.par(x)<<" "; cout<<endl;
	}
	
}