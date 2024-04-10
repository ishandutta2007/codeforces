#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,k;
ll a[N];
ll b[N];
ll ans=0;
typedef pair<ll,int> pli;
priority_queue<pli>pq;
ll f(ll x,ll y){
	ll z=x%y;
	ll t=x/y;
	return z*(t+1)*(t+1)+(y-z)*t*t;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		ans+=a[i]*a[i];
		b[i]=1;
		if(a[i]!=1) pq.push({f(a[i],1)-f(a[i],2),i});
	}
	for(int i=1; i<=k-n ;i++){
		//cout << i << ' ' << pq.size() << endl;
		auto cur=pq.top();pq.pop();
		ans-=cur.fi;
		int x=cur.se;
		b[cur.se]++;
		if(b[cur.se]==a[cur.se]) continue;
		pq.push({f(a[x],b[x])-f(a[x],b[x]+1),x});
	}
	cout << ans << '\n';
}