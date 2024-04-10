#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,m,a[N],p[N];
pair<int,int> q[N];
ll s[N],ans[N];
void Solve(){
	n=read(),m=read();
	ll mx=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i];
		mx=max(mx,s[i]);
	}
	for(int i=1;i<=m;++i){
		ans[i]=0;
		q[i]=make_pair(read(),i);
		if(s[n]<=0){
			if(q[i].first>mx)ans[i]=-1;
		}
		else{
			ans[i]=max(0LL,(q[i].first-mx+s[n]-1)/s[n]);
			q[i].first-=ans[i]*s[n];
			ans[i]*=n;
		}
	}
	sort(q+1,q+m+1);
	for(int i=0,j=1;i<=n;++i){
		while(j<=m&&s[i]>=q[j].first){
			if(~ans[q[j].second])ans[q[j].second]+=i;
			++j;
		}
	}
	for(int i=1;i<=m;++i){
		if(~ans[i])--ans[i];
	}
	for(int i=1;i<=m;++i){
		printf("%lld ",ans[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;	
}