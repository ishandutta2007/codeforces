//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
string s;
int arr[100005];
int cnt[20];

int can[20][20];

int mask[132000];
int bad[132000];

int reach[132000];


struct node{
	int s,e,m;
	int val;
	node *l,*r;

	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val=l->val|r->val;
		}
		else{
			val=arr[s];
		}
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)|r->query(m+1,j);
	}
}*root;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	cin>>s;
	
	rep(x,0,n){
		arr[x]=(1<<(s[x]-'a'));
		cnt[s[x]-'a']++;
	}
	
	root=new node(0,n-1);
	
	rep(x,0,k){
		rep(y,0,k) cin>>can[x][y];
	}
	
	int allflip=(1<<k)-1;
	
	rep(a,0,k) rep(b,a,k) if (!can[a][b]){
		memset(mask,0,sizeof(mask));
		
		int l=-1;
		
		rep(x,0,n) if (arr[x]==(1<<a) || arr[x]==(1<<b)){
			if (l!=-1 && min(arr[l],arr[x])==(1<<a) && max(arr[l],arr[x])==(1<<b)){
				if (l+1<=x-1) mask[allflip^root->query(l+1,x-1)]=1;
				else mask[allflip]=1;
			}
			
			l=x;
		}
		
		//cout<<a<<" "<<b<<":"<<endl;
		//rep(x,0,allflip+1) cout<<mask[x]<<" ";cout<<endl;
		
		int pp=(1<<a)|(1<<b);
		
		rep(x,allflip+1,0) if ((x&pp)==pp){
			if (!mask[x]) continue;
			
			bad[x]=1;
			
			int bm=x;
			while (bm){
				int temp=__builtin_ctz(bm);
				
				mask[x^(1<<temp)]=1;
				bm^=(1<<temp);
			}
		}
	}
	
	/*
	rep(x,0,allflip+1){
		cout<<x<<" "<<bad[x]<<endl;
	}
	*/
	
	reach[allflip]=1;
	
	int ans=1e9;
	rep(x,allflip+1,0){
		if (bad[x]) reach[x]=0;
		
		if (!reach[x]) continue;
		
		int curr=0;
		rep(bit,0,k) if (x&(1<<bit)) curr+=cnt[bit];
		
		//cout<<"debug: "<<x<<" "<<curr<<endl;
		
		ans=min(ans,curr);
		
		int bm=x;
		while (bm){
			int temp=__builtin_ctz(bm);
			
			reach[x^(1<<temp)]=1;
			bm^=(1<<temp);
		}
	}
	
	cout<<ans<<endl;
}