#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//ll
int n;
ll L[500005];
char ch[500005];
class segtree
{
public:
	#define s (1<<19)
	ll seg[s*2];
	ll lazy[s*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	ll update(int beg,int end,int idx,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=min(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	ll query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return 1500000000000000000LL;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return min(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
}kaede;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&L[i]);
	scanf("%s",&ch);
	ll cur = 0;
	ll ans = 0;
	bool ok = 0;
	rep(i,n){
		if(ch[i] == 'L') ans += L[i];
		else if(ch[i] == 'W') ans += L[i]*3LL;
		else ans += L[i]*5LL;
	}
	vector<ll>vec;
	int lasw,lasg;
	rep(i,n){
		if(ch[i] == 'G'){
			cur += L[i];
			kaede.update(i,i,0,0,s-1,cur);
			vec.pb(L[i]);
			lasg = i;
			continue;
		}
		if(ch[i] == 'W'){
			cur += L[i];
			lasw = i;
			ok = 1;
			kaede.update(i,i,0,0,s-1,cur);
			vec.pb(L[i]);
			continue;
		}
		if(ch[i] == 'L'){
			if(cur >= L[i]){
				cur -= L[i];
				kaede.update(i,i,0,0,s-1,cur);
				vec.pb(L[i]);
				continue;
			}
			else{
				ll need = L[i]-cur;
				if(ok){
					ans += 3LL*need;
					vec[lasw] += need;
				}
				else{
					ans += 5LL*need;
					vec[lasg] += need;
				}
				cur = 0; vec.pb(L[i]);
				kaede.update(i,i,0,0,s-1,cur);
				continue;
			}
		}
	}
	//ans
	//g
	for(int i=n-1;i>=0;i--){
	    if(ch[i] == 'L') continue;
	    if(ch[i] == 'W') continue;
		ll mn = kaede.query(i,n-1,0,0,s-1);
		if(2LL*vec[i] <= mn){
			kaede.update(i,n-1,0,0,s-1,-2LL*vec[i]);
			ans -= 4LL*vec[i];
		}
		else{
			kaede.update(i,n-1,0,0,s-1,-mn);
			ans -= 2LL*mn;
		}
	}
	//w
	for(int i=n-1;i>=0;i--){
	    if(ch[i] == 'L') continue;
	    if(ch[i] == 'G') continue;
		ll mn = kaede.query(i,n-1,0,0,s-1);
		if(2LL*vec[i] <= mn){
			kaede.update(i,n-1,0,0,s-1,-2LL*vec[i]);
			ans -= 2LL*vec[i];
		}
		else{
			kaede.update(i,n-1,0,0,s-1,-mn);
			ans -= 1LL*mn;
		}
	}
	cout<<ans<<endl;
}