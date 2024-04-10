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

int n,q;
int fen[1200005];

void add(int i,int j){
	while (i<1200005){
		fen[i]+=j;
		i+=i&-i;
	}
}

int find(int i){
	int curr=0;
	int tk=524288;
	while (tk){
		if (fen[curr|tk]<i){
			curr|=tk;
			i-=fen[curr];
		}
		tk>>=1;
	}
	
	return curr+1;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	
	int a;
	rep(x,0,n){
		cin>>a;
		add(a,1);
	}
	
	rep(x,0,q){
		cin>>a;
		if (a>0){
			add(a,1);
			n++;
		}
		else{
			add(find(-a),-1);
			n--;
		}
	}
	
	if (n==0) cout<<0<<endl;
	else cout<<find(1)<<endl;
}