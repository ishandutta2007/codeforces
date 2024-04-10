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

int n,k;
int nimsum;

int calc(int i){
	if (i==1) return 1;
	else if (i==2) return 0;
	else if (i==3) return 1;
	else if (i==4) return 2;
	else if (i%2==1) return 0;
	
	int a=calc(i/2);
	
	if (a==1) return 2;
	else return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	k&=1;
	
	int t;
	rep(x,0,n){
		cin>>t;
		
		if (k==0){
			if (t<=2) nimsum^=t;
			else nimsum^=(t+1)&1;
		}
		else{
			nimsum^=calc(t);
		}
	}
	
	if (nimsum==0) cout<<"Nicky"<<endl;
	else cout<<"Kevin"<<endl;
}