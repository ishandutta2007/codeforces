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

void rage(){
	cout<<"IMPOSSIBLE"<<endl;
	exit(0);
}

int n;
ll arr[200005];
ll brr[200005];

string ans;
ll num=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) cin>>brr[x];
	
	if (n==2){
		while (max(brr[0],brr[1])>max(arr[0],arr[1])){
			if (brr[0]>brr[1]){
				reverse(brr,brr+n);
				ans+='R';
			}
			
			ll erase=ceil((double)(brr[1]-MAX(arr[0],arr[1],brr[0]))/brr[0]);
			
			//cout<<erase<<endl;
			
			if (erase==0) rage();
			
			num+=erase;
			
			if (num<=200000) rep(x,0,erase) ans+='P';
			
			brr[1]-=brr[0]*erase;
		}
	}
	else if (n!=1){
		while (max(brr[0],brr[n-1])>max(arr[0],arr[n-1])){
			if (brr[0]>brr[n-1]){
				reverse(brr,brr+n);
				ans+='R';
			}
			
			rep(x,n,1){
				brr[x]-=brr[x-1];
				if (brr[x]<=0) rage();
			}
			ans+='P';
			num++;
		}
	}
	
	rep(x,0,n) if (arr[x]!=brr[x]){
		reverse(brr,brr+n);
		ans+='R';
		
		rep(x,0,n) if (arr[x]!=brr[x]) rage();
	}

	reverse(all(ans));
	
	if (num>200000){
		cout<<"BIG"<<endl;
		cout<<num<<endl;
	}
	else{
		cout<<"SMALL"<<endl;
		cout<<sz(ans)<<endl;
		cout<<ans<<endl;
	}
}