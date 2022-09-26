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
int n,m,a[N],p[N],ans[N];
ll s[N],c[N];
double t[N];
set<int> S;
multiset<int> len;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		static int st[N],top;
		while(top&&t[st[top]]>=(1.0*(s[i]-s[st[top]])/(i-st[top])))--top;
		t[i]=1.0*(s[i]-s[st[top]])/(i-st[top]);
		c[i]=ceil(1.0*(s[i]-s[st[top]])/(i-st[top]));
		p[i]=i;
		st[++top]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return c[i]<c[j];});
	S.insert(0);
	S.insert(n);
	len.insert(n);
	ans[0]=n;
	for(int i=1;i<=n;++i){
		int u=p[i];
		if(u==n){ans[i]=ans[i-1];continue;}
		auto it=S.lower_bound(u);
		int r=(*it);
		int l=(*--it);
		len.erase(len.find(r-l));
		len.insert(u-l);
		len.insert(r-u);
		S.insert(u);
		ans[i]=*--len.end();
	}
	for(int i=1,j=0;i<=m;++i){
		int k=read();
		while(j<n&&c[p[j+1]]<=k)++j;
		printf("%d ",ans[j]-1);
	}
	return 0;
}