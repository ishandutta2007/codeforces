#include<bits/stdc++.h>
using namespace std;
#define N 15005
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
int T,n,a[N],fL[2][N],fR[2][N];
inline int lowbit(int x){return x&(-x);}
class BIT1{
public:
	int b[N];
	void Clear(){for(int i=1;i<=n;++i)b[i]=inf;}
	inline void Add(int x,int d){
		while(x)b[x]=min(b[x],d),x-=lowbit(x);
	}
	inline int Ask(int x){
		int ans=inf;
		while(x<=n)ans=min(ans,b[x]),x+=lowbit(x);
		return ans;
	}
}B1;
class BIT2{
public:
	int b[N];
	void Clear(){for(int i=1;i<=n;++i)b[i]=-inf;}
	inline void Add(int x,int d){
		while(x<=n)b[x]=max(b[x],d),x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=-inf;
		while(x)ans=max(ans,b[x]),x-=lowbit(x);
		return ans;
	}
}B2;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	reverse(a+1,a+n+1);
	int ans=0;
	for(int myh=0;myh<=1;++myh){
		for(int i=2;i<=n;++i){
			if(!myh)fL[1][i]=inf,fR[1][i]=-inf;
			else fL[1][i]=fR[1][i]=a[i];
		}
		fL[1][1]=a[1],fR[1][1]=a[1];
		for(int k=2,t=2+myh;;++k,++t){
			B1.Clear();
			B2.Clear();
			for(int i=1;i<=n;++i){
				if(i-t+1>=1&&fR[(k-1)&1][i-t+1]>-inf)B1.Add(fR[(k-1)&1][i-t+1],a[i-t+1]);
				if(i-t+1>=1&&fL[(k-1)&1][i-t+1]<inf) B2.Add(fL[(k-1)&1][i-t+1],a[i-t+1]);
				fL[k&1][i]=B1.Ask(a[i]);
				fR[k&1][i]=B2.Ask(a[i]);
				B1.Add(a[i],fL[(k-1)&1][i]);
				B2.Add(a[i],fR[(k-1)&1][i]);
			}
			bool ok=false;
			for(int i=1;i<=n;++i){
				if(fL[k&1][i]^inf||fR[k&1][i]^(-inf))ok=true;	
			}
			if(!ok){
				ans=max(ans,k-1);
				break;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}