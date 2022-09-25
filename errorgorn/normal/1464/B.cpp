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
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

string s;
int a,b;

long long arr[100005]; //initialize to 0, this is 1-indexed
void update(int i,long long j){ //adds j to ith term
    while (i<100005){
        arr[i]+=j;
        i+=(i&(-i));
    }
}
long long query(int i){ //calculate the sum of the 0-i terms
    long long k=0;
    while (i>0){
        k+=arr[i];
        i-=(i&(-i));
    }
    return k;
}
ll query0(int i,int j){
	if (j<i) return 0;
	return (j-i+1)-(query(j)-(i?query(i-1):0));
}
ll query1(int i,int j){
	if (j<i) return 0;
	return query(j)-(i?query(i-1):0);
}




int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>s;
	cin>>a>>b;
	
	int n=sz(s);
	s="$"+s;
	
	ll ans=0;
	rep(x,1,sz(s)){
		if (s[x]=='1'){
			ans+=query0(1,x-1)*a;
			update(x,1);
		}
		else{
			ans+=query1(1,x-1)*b;
		}
	}
	
	//everything is 0
	//cout<<ans<<endl;
	ll best=ans;
	rep(x,1,sz(s)){
		if (s[x]=='?'){
			ans-=query1(1,x-1)*b;
			ans-=query1(x+1,n)*a;
			ans+=query0(1,x-1)*a;
			ans+=query0(x+1,n)*b;
			update(x,1);
			//cout<<ans<<endl;
		}
		best=min(best,ans);
	}
	
	rep(x,1,sz(s)){
		if (s[x]=='?'){
			ans+=query1(1,x-1)*b;
			ans+=query1(x+1,n)*a;
			ans-=query0(1,x-1)*a;
			ans-=query0(x+1,n)*b;
			update(x,-1);
		}
		best=min(best,ans);
	}
	
	cout<<best<<endl;
}