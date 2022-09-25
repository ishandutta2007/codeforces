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

const int MOD=998244353;

int n,k,m;
vector<iii> cond;
vector<ii> zeros;
vector<ii> ones; 

bool one[500005];
int pcnt[500005];

ll fix(ll i){
	while (i<0) i+=MOD;
	while (MOD<=i) i-=MOD;
	
	return i;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>m;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		
		cond.push_back(iii(ii(a,b),c));
	}
	
	sort(all(cond),[](iii &i,iii &j){
		if (i.fi.fi!=j.fi.fi) return i.fi.fi<j.fi.fi;
		else return i.fi.se>j.fi.se;
	});
	
	ll ans=1;
	
	rep(bit,0,k){
		zeros.clear();
		ones.clear();
	
		for (auto &it:cond){
			ii val=it.fi;
		
			if (it.se&(1<<bit)){ //1 bit here
				if (!ones.empty() && val.fi<=ones.back().se) 
					ones.back().se=max(ones.back().se,val.se);
				else ones.push_back(val);
			}
			else{ //0 bit here
				while (!zeros.empty() && val.se<=zeros.back().se){
					zeros.pop_back();
				}
				zeros.push_back(val);
			}
		}
		
		/*
		debug(bit);
		
		cout<<"zeros"<<endl;
		for (auto &it:zeros) cout<<it.fi<<" "<<it.se<<endl;
		cout<<"ones"<<endl;
		for (auto &it:ones) cout<<it.fi<<" "<<it.se<<endl;
		//*/
		
		memset(one,false,sizeof(one));
		for (auto &it:ones) rep(x,it.fi,it.se+1) one[x]=true;
		
		pcnt[0]=1;
		
		int idx=0;
		rep(x,1,n+1){
			if (one[x]){
				pcnt[x]=pcnt[x-1];
			}
			else {
				if (idx==0) pcnt[x]=fix(pcnt[x-1]+pcnt[x-1]);
				else{
					pcnt[x]=fix(pcnt[x-1]+pcnt[x-1]-pcnt[zeros[idx-1].fi-1]);
				}
			}
			
			while (idx!=sz(zeros) && zeros[idx].se<x+1) idx++;
		}
		
		if (idx==0) ans=ans*pcnt[n]%MOD;
		else ans=ans*fix(pcnt[n]-pcnt[zeros[idx-1].fi-1])%MOD;
	}
	
	cout<<ans<<endl;
}