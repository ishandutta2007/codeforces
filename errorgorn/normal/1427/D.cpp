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

int n;
int arr[55];
int brr[55];

int adx=0;
vector<int> ans[55];

void oper(vector<int> v){
	int f=0;
	int b=n;
	
	for (auto &it:v) if (it) ans[adx].push_back(it);
	adx++;
	
	for (auto &it:v){
		b-=it;
		rep(x,0,it){
			brr[b+x]=arr[f+x];
		}
		f+=it;
	}
	
	swap(arr,brr);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,2,n+1){
		int idx;
		rep(y,0,n) if (arr[y]==1) idx=y;
		
		int idx2;
		rep(y,0,n) if (arr[y]==x) idx2=y;
		
		vector<int> v;
		if (arr[idx+1]==2){ //fwd 1,2,3
			if (idx2<idx){
				v.push_back(idx2);
				v.push_back(idx-idx2);
				v.push_back(x-1);
				v.push_back(n-idx-x+1);
			}
			else{
				v.push_back(idx);
				rep(zzz,0,x-1) v.push_back(1);
				v.push_back(idx2-idx-x+2);
				v.push_back(n-idx2-1);
			}
		}
		else{ //bwd ...,3,2,1
			if (idx2<idx){
				v.push_back(idx2);
				v.push_back(idx-idx2-x+2);
				rep(zzz,0,x-1) v.push_back(1);
				v.push_back(n-idx-1);
			}
			else{
				v.push_back(idx-x+2);
				v.push_back(x-1);
				v.push_back(idx2-idx);
				v.push_back(n-idx2-1);
			}
		}
		
		oper(v);
		//for (auto &it:v) cout<<it<<" "; cout<<endl;
		//cout<<"debug: "<<endl;
		//rep(x,0,n) cout<<arr[x]<<" "; cout<<endl;
	}
	if (arr[0]!=1){
		vector<int> v(n,1);
		oper(v);
	}
	
	cout<<adx<<endl;
	rep(x,0,adx){
		cout<<sz(ans[x])<<" ";
		for (auto &it:ans[x]) cout<<it<<" "; cout<<endl;
	}
	
	//rep(x,0,n) cout<<arr[x]<<" "; cout<<endl;
}