#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 600002
const int mx=200000;
const int mod=998244353;
const int G=3;
inline int read(){
	int x=0,f=1;
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
typedef vector<int> poly;
int n,x,y,tr[N],ans[N],Q;
inline int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int invG=qpow(G,mod-2);
int NTT_init(int n){
	int lim=1;
	while(lim<n)lim<<=1;
	for(int i=0;i<lim;++i){
		tr[i]=(tr[i>>1]>>1)|((i&1)?lim>>1:0);
	}
	return lim;
}
#define ck(x) (x>=mod?x-mod:x)
void NTT(poly &f,bool flag,int n){
	f.resize(n);
	for(int i=0;i<n;++i){
		if(i<tr[i])swap(f[i],f[tr[i]]);
	}
	for(int p=2;p<=n;p<<=1){
		int len=p>>1;
		int wn=qpow(flag?G:invG,(mod-1)/p);
		for(int k=0;k<n;k+=p){
			int buf=1;
			for(int i=k;i<k+len;++i){
				int t=1LL*buf*f[i+len]%mod;
				f[i+len]=ck(f[i]-t+mod);
				f[i]=ck(f[i]+t);
				buf=1LL*buf*wn%mod;
			}
		}
	}
	if(!flag){
		int invn=qpow(n,mod-2);
		for(int i=0;i<n;++i){
			f[i]=1LL*f[i]*invn%mod;
		}
	}
}	
poly Mul(poly A,poly B){
	int n=A.size()+B.size()-1;
	int lim=NTT_init(n);
	poly P(lim);
	NTT(A,1,lim),NTT(B,1,lim);
	for(int i=0;i<lim;++i){
		P[i]=1LL*A[i]*B[i]%mod;
	}
	NTT(P,0,lim);
	P.resize(n);
	return P;
}
int main(){
	n=read(),x=read(),y=read();
	poly A(x+1),B(x+1);
	for(int i=0;i<=n;++i){
		A[read()]=1;
	}
	B=A;
	reverse(B.begin(),B.end());
	poly C=Mul(A,B);
	for(int i=1;i<=x;++i){
		if(C[i+x]){
			int gu=i+y;
			for(int j=gu;j<=500000;j+=gu){
				ans[j]=max(ans[j],gu);
			}
		}
	}
	Q=read();
	while(Q--){
		int L=read();
		printf("%d ",L&1||!ans[L>>1]?-1:ans[L>>1]<<1);
	}
	return 0;
}