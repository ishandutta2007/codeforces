#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
const int N=2e5+5;
const ll mod=998244853;
int n,m,sz,k,q,b[N],arr[N];
vector<pll> cur;
pii a[N];
ll ans,d1,d2,mn=1e18;
void Do(int s,int e)
{
	sz=e-s+1;
	for(int i=1;i<=sz;i++) arr[i]=a[i+s-1].se;
	ll ps=arr[1],pe=arr[sz],d=pe-ps;
	d1=1e18; d2=1e18;
	for(auto &it : cur){
		ll x=it.fi,c=it.se;
		if(x<ps){
			d1=min(d1,c+ps-x+d*2LL);
			d2=min(d2,c+pe-x);
		}
		else if(x<pe){
			d1=min(d1,c+pe-x+d);
			d2=min(d2,c+x-ps+d);
		}
		else{
			d1=min(d1,c+x-ps);
			d2=min(d2,c+x-pe+d*2LL);
		}
	}
	//cout<<a[s].fi<<" : "<<s<<" - "<<e<<" -> "<<d1<<" , "<<d2<<endl;
	cur.clear();
	ll p=lower_bound(b+1,b+1+q,ps)-b;
	if(p<=q) cur.push_back(pll(b[p],min(d1+abs(b[p]-ps),d2+abs(b[p]-pe))));
	if(p>1) cur.push_back(pll(b[p-1],min(d1+abs(b[p-1]-ps),d2+abs(b[p-1]-pe))));
	p=lower_bound(b+1,b+1+q,pe)-b;
	if(p<=q) cur.push_back(pll(b[p],min(d1+abs(b[p]-ps),d2+abs(b[p]-pe))));
	if(p>1) cur.push_back(pll(b[p-1],min(d1+abs(b[p-1]-ps),d2+abs(b[p-1]-pe))));
	//for(auto &it : cur) cout<<it.fi<<" -> "<<it.se<<endl;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k>>q;
	for(int i=1;i<=k;i++) cin>>a[i].fi>>a[i].se;
	sort(a+1,a+1+k);
	for(int i=1;i<=q;i++) cin>>b[i];
	sort(b+1,b+1+q);
	ans=a[k].fi-1;
	if(a[1].fi!=1) cur.push_back(pll(b[1],b[1]-1));
	else cur.push_back(pll(1,0));
	for(int i=1;i<=k;i++){
		int j=i;
		while(j+1<=k&&a[i].fi==a[j+1].fi) j++;
		Do(i,j);
		i=j;
	}
	cout<<ans+min(d1,d2);
    return 0;
}