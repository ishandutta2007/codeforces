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

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(128705);

const int MOD=1000000007;
int base[300005];

int n,m;
vector<int> al[300005];
int hh[300005];

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

int p[300005];
bool useless[300005];
int w[300005];

int find(int i){
	if (i==p[i]) return i;
	else return find(p[i]);
}

void unions(int i,int j){
	i=find(i),j=find(j);
	
	if (i==j) return;
	useless[j]=true;
	p[j]=i;
}

void rage(){
	cout<<"NO"<<endl;
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,0,300005) base[x]=rng()%MOD;
	rep(x,0,300005) p[x]=x;
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	rep(x,1,n+1){
		for (auto &it:al[x]) hh[x]=(hh[x]+base[it])%MOD;
	}
	
	rep(x,1,n+1){
		for (auto &it:al[x]){
			if (fix(hh[x]-base[it])==fix(hh[it]-base[x])){
				unions(x,it);
			}
		}
	}
	
	int curr=-1;
	
	rep(x,1,n+1) if (!useless[x]){
		int deg=0;
		for (auto &it:al[x]){
			if (!useless[it]) deg++;
		}
		
		//cout<<x<<" "<<deg<<endl;
		if (deg>2) rage();
		else if (deg<=1) curr=x;
	}
	
	if (curr==-1) rage();
	
	int p=-1;
	int cw=1;
	while (true){
		w[curr]=cw++;
		
		int temp=-1;
		for (auto &it:al[curr]) if (!useless[it] && it!=p){
			temp=it;
			p=curr;
			break;
		}
		
		if (temp==-1) break;
		curr=temp;
	}
	
	cout<<"YES"<<endl;
	rep(x,1,n+1) cout<<w[find(x)]<<" "; cout<<endl;
}