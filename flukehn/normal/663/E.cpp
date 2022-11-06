#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+11;

char s[N];
int n,m;
int a[N];

const int M=(1<<20)+2;
ll b[M],c[M];
template<typename T>
inline void FWT(T *A,int n,int f=1){
	for(int i=1;i<(1<<n);i<<=1){
		for(int j=0;j<(1<<n);j+=i<<1){
			for(int k=0;k<i;++k){
				T x=A[j+k],y=A[j+k+i];
				if(f){
					A[j+k]=x+y;
					A[j+k+i]=x-y;
				}else{
					A[j+k]=(x+y)>>1;
					A[j+k+i]=(x-y)>>1;
				}
			}
		}
	}
}
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",s);
		for(int j=0;j<m;++j){
			a[j]|=(s[j]-'0')<<i;
		}
	}
	for(int i=0;i<m;++i)++b[a[i]];
	for(int i=0;i<(1<<n);++i){
		int t=__builtin_popcount(i);
		c[i]=min(t,n-t);
	}
	FWT(b,n),FWT(c,n);
	for(int i=0;i<(1<<n);++i)b[i]*=c[i];
	FWT(b,n,0);
	ll ans=1e18;
	for(int i=0;i<(1<<n);++i){
		//cout<<i<<" "<<b[i]<<endl;
		ans=min(ans,b[i]);
	}
	cout<<ans<<endl;
}