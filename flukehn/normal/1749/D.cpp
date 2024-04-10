#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int mo=998244353;
const int N=3e5+11;
bool np[N];
int p[N], mu[N];
int p_tot;
void init(){
	mu[1]=1;
	np[1]=1;
	for(int i=2;i<N;++i){
		if(!np[i]){
			p[p_tot++]=i;
			mu[i]=-1;
		}
		for(int j=0,k;j<p_tot&&(k=i*p[j])<N;++j){
			np[k]=1;
			if(i%p[j]==0){
				mu[k]=0;
				break;
			}
			mu[k]=-mu[i];
		}
	}
}
int n;
ll m;
int solve(){
	int t1=1;
	int t2=1;
	ll now=1;
	int ret=0;
	for(int i=1;i<=n;++i) {
		if(!np[i]) {
			if(now > m/i) {t1=0;}
			else now*=i;
		}
		//dbg(i, now);
		t1=m/now%mo*t1%mo;
		t2=m%mo*t2%mo;
		ret=(ret+t2-t1)%mo;
	}
	return (ret+mo)%mo;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	init();
	while(cin>>n>>m){
		cout<<solve()<<"\n";
	}
}