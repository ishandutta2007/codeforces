#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
ll n;
map<ll,ll> M;
ll F(ll x){
	if(x&1)return x/2+1;
	//if(M.count(x))return M[x];
	return F(x+n-x/2);
}
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int q;
	cin>>n>>q;
	while(q--){
		ll x;cin>>x;
		printf("%lld\n",F(x));
	}
}