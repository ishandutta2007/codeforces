#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
int len;
struct Matrix{
	int g[13*(1<<4)][13*(1<<4)];
	Matrix(){memset(g,0,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=0;i<len;++i){
			for(int j=0;j<len;++j){
				for(int k=0;k<len;++k){
					c.g[i][j]=(c.g[i][j]+1LL*a.g[i][k]*b.g[k][j])%mod;
				}
			}
		}
		return c;
	}	
}e,pre,A;
Matrix mpow(Matrix a,int b){
	Matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int n,K,m,all,cnt[1<<4];
inline int ID(int x,int y){
	return x*(1<<m)+y;
}
int main(){
	n=read(),K=read(),m=read();
	all=(1<<m)-1;
	len=(K+1)*(1<<m);
	for(int i=0;i<len;++i)e.g[i][i]=1;
	for(int i=1;i<=all;++i)cnt[i]=cnt[i>>1]+(i&1);
	pre.g[0][ID(0,0)]=1;
	for(int j=0;j<=K;++j){
		for(int s=0;s<=all;++s){
			++A.g[ID(j,s)][ID(j,(s<<1)&all)];
			if(j<K)A.g[ID(j,s)][ID(j+1,(s<<1)&all|1)]+=cnt[s]+1;
		}	
	}
	Matrix t=pre*mpow(A,n);
	int ans=0;
	for(int i=0;i<=all;++i){
		ans=(ans+t.g[0][ID(K,i)])%mod;
	}
	printf("%d\n",ans);
	return 0;
}