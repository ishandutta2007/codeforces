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

int n;
int ans[105];
int ds[105]; //delta straight

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	int pt,ps;
	cin>>pt>>ps;
	
	int t,s;
	rep(x,n,3){
		cout<<"+ "<<x<<endl;
		cin>>t>>s;
		ds[x]=s-ps;
		
		pt=t,ps=s;
	}
	
	int diff=0;
	
	cout<<"+ "<<1<<endl;
	cin>>t>>s;
	ds[1]=s-ps;
	diff+=t-pt;
	
	pt=t,ps=s;
	
	cout<<"+ "<<2<<endl;
	cin>>t>>s;
	ds[2]=s-ps;
	
	pt=t,ps=s;
	
	cout<<"+ "<<1<<endl;
	cin>>t>>s;
	diff+=t-pt;
	
	diff=(int)(sqrt(diff)+0.5);
	
	ans[1]=diff;
	ans[3]=s-ps-ds[1]-1;
	ans[2]=ds[1]/(ans[3]+1);
	
	ans[4]=(ds[2])/(ans[3]+1)-ans[1]-2;
	rep(x,5,n+1){
		ans[x]=(ds[x-2]-ans[x-3]*ans[x-4])/(ans[x-1]+1)-ans[x-3]-1;
	}
	
	ans[n]++;
	
	cout<<"! ";
	rep(x,1,n+1) cout<<ans[x]<<" ";
}