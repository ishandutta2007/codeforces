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

int n;
int arr[300005]; //input
int brr[300005]; //answer
int crr[300005];

int pp[300005];
vector<int> al[300005];
int d[300005];

vector<int> stk;

int IDX=0;
void dfs(int i,int p){
	pp[i]=p;
	
	brr[i]=IDX++;
	vector<int> childs;
	for (auto it:al[i]){
		if (it==p) continue;
		childs.pub(it);
	}
	
	sort(all(childs),[](int i,int j){
		return arr[i]<arr[j];
	});
	
	for (auto it:childs){
		d[it]=d[i]+1;
		dfs(it,i);
	}
	
	stk.pub(i);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1){
		cin>>arr[x];
		arr[x]--;
	}
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs(1,-1);
	
	int idx;
	int ans=0;
	rep(x,0,n){
		if (x==n-1 || arr[stk[x]]!=x){
			idx=x;
			break;
		}
		crr[stk[x]]=x;
		ans+=d[stk[x]];
	}
	
	//cout<<idx<<endl;
	
	vector<int> pos;
	rep(x,idx,n) pos.pub(stk[x]);
	sort(all(pos),[](int i,int j){
		return brr[i]<brr[j];
	});
	
	rep(x,0,sz(pos)) crr[pos[x]]=x+idx;
	
	// rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
	// rep(x,1,n+1) cout<<crr[x]<<" "; cout<<endl;
	
	int curr=1;
	while (crr[curr]!=arr[curr]){
		int best=-1;
		int mn=1e18;
		for (auto it:al[curr]) if (it!=pp[curr]){
			if (crr[it]>crr[curr] && crr[it]<mn){
				mn=crr[it];
				best=it;
			}
		}
		
		if (best!=-1){
			swap(crr[curr],crr[best]);
			curr=best;
			ans++;
		}
		else{
			break;
		}
	}
	
	rep(x,1,n+1) if (arr[x]!=crr[x]){
		cout<<"NO"<<endl;
		exit(0);
	}
	
	cout<<"YES"<<endl;
	cout<<ans<<endl;
	rep(x,1,n+1) cout<<brr[x]+1<<" "; cout<<endl;
}