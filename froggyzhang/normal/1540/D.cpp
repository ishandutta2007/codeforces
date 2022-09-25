#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define B 505
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
int Q,n,a[N],len,pos[N],blocks;
int L[N],R[N];
vector<int> V[B];
struct BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Find(int t){
		int ans=0;
		for(int i=17;i>=0;--i){
			if(ans+(1<<i)<=n&&b[ans+(1<<i)]+(1<<i)<t){
				ans+=1<<i;
				t-=b[ans]+(1<<i);
			}
		}
		return ans+1;
	}
}C;
void build(int x){
	V[x].clear();
	for(int i=L[x];i<=R[x];++i){
		int p=C.Find(a[i]+1)-1;
		V[x].push_back(p);
		C.Add(p+1,1);
	}
	for(auto p:V[x])C.Add(p+1,-1);
	sort(V[x].begin(),V[x].end());
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	len=min(n,200);
	blocks=n/len;
	if(n%len)++blocks;
	for(int i=1;i<=blocks;++i){
		L[i]=(i-1)*len+1,R[i]=min(n,i*len);
		for(int j=L[i];j<=R[i];++j)pos[j]=i;
	}
	for(int i=1;i<=blocks;++i)build(i);
	Q=read();
	while(Q--){
		int opt=read();
		if(opt==1){
			int i=read();
			a[i]=read();
			build(pos[i]);	
		}
		else{
			int x=read();
			int t=a[x];
			for(int i=x+1;i<=R[pos[x]];++i)t+=a[i]<=t;
			for(int i=pos[x]+1;i<=blocks;++i)t+=upper_bound(V[i].begin(),V[i].end(),t)-V[i].begin();
			printf("%d\n",n-t);
		}
	}
	return 0;
}