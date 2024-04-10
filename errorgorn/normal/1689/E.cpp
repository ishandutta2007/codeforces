// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
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
	int p[2005];
	
	void reset(int n){
		rep(x,1,n+1) p[x]=x;
	}
	
	int par(int i){
		if (p[i]==i) return p[i];
		else return p[i]=par(p[i]);
	}
	
	void unions(int i,int j){
		i=par(i),j=par(j);
		p[i]=j;
	}
} ufds;

int n;
int arr[2005];
vector<int> pos[2005];

bool ok(){
	ufds.reset(n);
	rep(bit,0,30){
		int idx=-1;
		rep(x,1,n+1) if (arr[x]&(1<<bit)){
			if (idx==-1) idx=x;
			ufds.unions(idx,x);
		}
	}
	
	rep(x,1,n+1) if (ufds.par(1)!=ufds.par(x)) return false;
	return true;
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
		int op=0;
		rep(x,1,n+1) if (arr[x]==0) arr[x]++,op++;
		ufds.reset(n);
		
		rep(bit,0,30){
			int idx=-1;
			rep(x,1,n+1) if (arr[x]&(1<<bit)){
				if (idx==-1) idx=x;
				ufds.unions(idx,x);
			}
		}
		
		rep(x,1,n+1) pos[x].clear();
		rep(x,1,n+1) pos[ufds.par(x)].pub(x);
		
		int best=-1;
		int idx=-1;
		int cnt=0;
		rep(x,1,n+1) if (!pos[x].empty()){
			cnt++;
			
			int mask=0;
			for (auto it:pos[x]) mask|=arr[it];
			
			if (__builtin_ctz(mask)>best){
				best=__builtin_ctz(mask);
				idx=x;
			}
		}
		
		if (cnt==1){
			cout<<op<<endl;
			rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
			continue;
		}
		else{
			bool flag=false;
			rep(x,1,n+1){
				arr[x]--;
				if (ok()){
					cout<<op+1<<endl;
					rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
					flag=true;
					break;
				}
				arr[x]+=2;
				if (ok()){
					cout<<op+1<<endl;
					rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
					flag=true;
					break;
				}
				arr[x]--;
			}
			
			if (!flag){
				vector<int> v2;
				for (auto it:pos[idx]) if (arr[it]&(1<<best)) v2.pub(it);
				assert(sz(v2)>=2);
				
				arr[v2[0]]--;
				arr[v2[1]]++;
				cout<<op+2<<endl;
				rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
			}
		}
	}
}