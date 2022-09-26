#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 500050
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
int n,m,a[N],b[N],ans;
bool ok[N];
struct BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	void Add(int x,int d){
		while(x<=n){
			b[x]=max(b[x],d);
			x+=lowbit(x);
		}
	}
	int Ask(int x){
		int ans=0;
		while(x){
			ans=max(ans,b[x]);
			x-=lowbit(x);
		}
		return ans;
	}
	void Clear(int x){
		while(x<=n){
			b[x]=0;
			x+=lowbit(x);
		}
	}
}B;
int Solve(int l,int r){
	static int t[N],len;
	len=0;
	for(int i=l;i<=r;++i){
		if(a[i]>=a[l-1]&&a[i]<=a[r+1])ok[i]=true,t[++len]=a[i];
	}
	if(!len)return 0;
	sort(t+1,t+len+1);
	len=unique(t+1,t+len+1)-t-1;
	int mx=0;
	for(int i=l;i<=r;++i){
		if(!ok[i])continue;
		a[i]=lower_bound(t+1,t+len+1,a[i])-t;
		int tmp=B.Ask(a[i])+1;
		mx=max(mx,tmp);
		B.Add(a[i],tmp);
	}
	for(int i=l;i<=r;++i){
		if(ok[i])B.Clear(a[i]);
	}
	return mx;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read()-i;
	}
	for(int i=1;i<=m;++i){
		b[i]=read();
	}
	ans=n-m;
	b[++m]=n+1;
	a[0]=-1e9,a[n+1]=1e9;
	for(int i=1;i<=m;++i){
		if(a[b[i-1]]>a[b[i]])return !printf("-1\n");
		ans-=Solve(b[i-1]+1,b[i]-1);
	}
	printf("%d\n",ans);
	return 0;
}