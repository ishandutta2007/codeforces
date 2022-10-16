#include<bits/stdc++.h>
using namespace std;
#define  N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,Q,a[N],p[N],pn;
bool ntp[N];
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
}
map<int,int> mp;
void Solve(){
	mp.clear();
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		for(int j=1;j<=pn;++j){
			while(a[i]%(p[j]*p[j])==0)a[i]/=p[j]*p[j];
		}
		++mp[a[i]];
	}
	int ans=0,t=0;
	for(auto x:mp)ans=max(ans,x.second);
	int tot=0;
	t=ans;
	for(auto x:mp)if(x.first==1||x.second%2==0)tot+=x.second;
	t=max(t,tot);
	Q=read();
	while(Q--){
		ll x=read();
		printf("%d\n",!x?ans:t);
	}
}
int main(){
	init(1000);
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}