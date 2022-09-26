#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
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
int n,a[N],b[N],c[N<<1],len;
ll ans,all;
inline int lowbit(int x){return x&(-x);}
struct QAQ{
	struct BIT1{
		int b[N<<1];
		void Clear(){
			memset(b,0x3f,sizeof(b));
		}
		inline void Add(int x,int d){
			while(x)b[x]=min(b[x],d),x-=lowbit(x);
		}
		inline int Ask(int x){
			int ans=inf;
			while(x<=len)ans=min(ans,b[x]),x+=lowbit(x);
			return ans;
		}
	}B1;
	struct BIT2{
		int b[N<<1];
		void Clear(){
			memset(b,0,sizeof(b));
		}
		inline void Add(int x,int d){
			while(x<=len)b[x]=max(b[x],d),x+=lowbit(x);
		}
		inline int Ask(int x){
			int ans=0;
			while(x)ans=max(ans,b[x]),x-=lowbit(x);
			return ans;
		}
	}B2;
}A[2];
void Solve(){
	A[0].B1.Clear(),A[0].B2.Clear();
	A[1].B1.Clear(),A[1].B2.Clear();
	for(int i=1;i<=n;++i){
		int t=0,l=a[i],r=b[i];
		if(l>r)swap(l,r),t=1;
		int j1=A[t].B1.Ask(r);
		int j2=A[t].B2.Ask(l);
		if(j1^inf)ans=min(ans,all-2*(c[r]-max(c[l],c[j1])));
		if(j2^0)ans=min(ans,all-2*(min(c[r],c[j2])-c[l]));
		A[t^1].B2.Add(l,r);
		A[t^1].B1.Add(r,l);
	}	
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),c[++len]=a[i];
	for(int i=1;i<=n;++i)b[i]=read(),c[++len]=b[i];
	for(int i=1;i<=n;++i)all+=abs(a[i]-b[i]);
	sort(c+1,c+len+1);
	len=unique(c+1,c+len+1)-c-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(c+1,c+len+1,a[i])-c;
		b[i]=lower_bound(c+1,c+len+1,b[i])-c;
	}
	ans=all;
	Solve();
	reverse(a+1,a+n+1);
	reverse(b+1,b+n+1);
	Solve();
	printf("%lld\n",ans);
	return 0;
}