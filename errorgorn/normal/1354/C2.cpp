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

const long double PI=acos(-1);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		
		long double diag=0.5/sin(PI/(n*2));
		
		//cout<<diag<<endl;
		
		long double angle1=PI/n*(n/2),angle2=PI-angle1;
		long double side1=sqrt(diag*diag*2-2*diag*diag*cos(angle1));
		long double side2=sqrt(diag*diag*2-2*diag*diag*cos(angle2));
		
		//cout<<side1<<" "<<side2<<endl;
		
		cout<<setprecision(12)<<(side1+side2)/sqrt(2)<<endl;
		
	}
}