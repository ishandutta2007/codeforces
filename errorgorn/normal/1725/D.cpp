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

int n,q;
int arr[100005];

int fen[200005];

void upd(int i,int j){
	while (i<200005){
		fen[i]+=j;
		i+=i&-i;
	}
}

int query(int i){
	int res=0;
	while (i){
		res+=fen[i];
		i-=i&-i;
	}
	return res;
}

int f[400005];
int b[400005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(i,0,1<<17) if (i%2==1){
		int B=31-__builtin_clz(i);
		int A=i-(1<<B);
		int j=(A<<(17-B))+1;
		
		f[i]=j;
		b[j]=i;
	}
	
	cin>>n>>q;
	rep(x,0,q) cin>>arr[x];
	
	int curr=n;
	int ans=0;
	int lim=1;
	int extra=0;
	while (true){
		int temp=min(curr,(lim+1)/2);
		curr-=temp;
		ans+=lim*temp;
		extra=(lim+1)/2-temp;
		if (curr==0) break;
		lim++;
	}
	
	cout<<ans<<endl;
	
	vector<ii> ins,del;
	rep(x,lim+1,1) if (x%2==1){
		int len=lim-(x-1);
		int l=32-__builtin_clz(x);
		int r=l+len-1;
		if (extra){
			r--;
			extra--;
		}
		
		ins.pub({l,x});
		del.pub({r,x});
	}
	
	reverse(all(del));
	
	int idx=0;
	curr=1;
	
	rep(x,1,100005){
		while (!ins.empty() && ins.back().fi==x){
			upd(f[ins.back().se],1);
			ins.pob();
		}
		
		while (idx<q && arr[idx]<curr+fen[1<<17]){
			int val=arr[idx]-curr;
			
			int lo=0,hi=1<<17,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (query(mi)<=val) lo=mi;
				else hi=mi;
			}
			
			cout<<b[hi]+(x-(32-__builtin_clz(b[hi])))<<endl;
			
			idx++;
		}
		
		curr+=fen[1<<17];
		
		
		while (!del.empty() && del.back().fi==x){
			upd(f[del.back().se],-1);
			del.pob();
		}
	}
	
}