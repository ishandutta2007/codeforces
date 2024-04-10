#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=16e5+1;
const ll mod=1e9+7;
int n;
ll x[N],y[N];
int a[N];
ll b[N];
bool cmp(int u,int v){
	return x[u]<x[v];
}
ll ssk=0;
inline void ping2(int u){
	y[u]-=ssk-x[u];
	x[u]=ssk;
}
inline void ping3(int u){
	y[u]+=ssk-x[u];
	x[u]=ssk;
}

class cmp2{
	public:
		bool operator()(int u,int v){
			ping2(u);ping2(v);
			return y[u]<y[v];
		}
};
class cmp3{
	public:
		bool operator()(int u,int v){
			ping3(u);ping3(v);
			return y[u]>y[v];
		}
};
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll cx,cy;cin >> cx >> cy;
		x[i]=cx+cy;x[i+n]=cx+cy;
		y[i]=cx-cy;y[i+n]=cx-cy;
		a[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n ;i++) b[i]=x[a[i]];
	priority_queue<int,vector<int>,cmp2>pq2;
	priority_queue<int,vector<int>,cmp3>pq3;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ans-=2LL*(i-1)*(b[i]-b[i-1]);
		ssk=b[i];
		pq2.push(a[i]);pq3.push(a[i]+n);
		while(true){
			int c=pq2.top();ping2(c);
			int d=pq3.top();ping3(d);
			if(y[c]<=y[d]) break;
			pq2.pop();pq3.pop();
			pq2.push(d);pq3.push(c);
		}
	}
	while(!pq2.empty()){
		ping2(pq2.top());
		ans-=y[pq2.top()];
		pq2.pop();
	}
	
	while(!pq3.empty()){
		ping3(pq3.top());
		ans+=y[pq3.top()];
		pq3.pop();
	}
	cout << ans/4 << '\n';
}