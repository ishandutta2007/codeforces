#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=1050000,g=3,invg=(mod+1)/3;
int n,f[N+5],a[N+5],jc[N+5],ny[N+5],cnt[N+5];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
namespace Conv{

int wk[N+5],ta[N+5],tb[N+5];
void DFT(int *a,int n){
	for(int i=n>>1;i;i>>=1){
		int w=Power(g,(mod-1)/(i<<1));
		wk[0]=1;
		for(int j=1;j<i;j++)wk[j]=1ll*wk[j-1]*w%mod;
		for(int j=0;j<n;j+=(i<<1)){
			for(int k=0;k<i;k++){
				int x=a[j+k],y=a[i+j+k],z=x;
				x+=y,(x>=mod&&(x-=mod)),a[j+k]=x;
				z-=y,(z<0&&(z+=mod)),a[i+j+k]=1ll*z*wk[k]%mod;
			}
		}
	}
}
void IDFT(int *a,int n){
	for(int i=1;i<n;i<<=1){
		int w=Power(invg,(mod-1)/(i<<1));
		wk[0]=1;
		for(int j=1;j<i;j++)wk[j]=1ll*wk[j-1]*w%mod;
		for(int j=0;j<n;j+=(i<<1)){
			for(int k=0;k<i;k++){
				int x=a[j+k],y=1ll*a[i+j+k]*wk[k]%mod,z=x;
				x+=y,(x>=mod&&(x-=mod)),a[j+k]=x;
				z-=y,(z<0&&(z+=mod)),a[i+j+k]=z;
			}
		}
	}
	for(int i=0,inv=Power(n,mod-2);i<n;i++)a[i]=1ll*a[i]*inv%mod;
}
vector<int> conv(vector<int> A,vector<int> B){
	int sa=A.size(),sb=B.size();
	vector<int> ret(sa+sb-1);
	int len=1;
	while(len<ret.size())len<<=1;
	for(int i=0;i<len;i++)ta[i]=tb[i]=0;
	for(int i=0;i<sa;i++)ta[i]=A[i];
	for(int i=0;i<sb;i++)tb[i]=B[i];
	DFT(ta,len),DFT(tb,len);
	for(int i=0;i<len;i++)ta[i]=1ll*ta[i]*tb[i]%mod;
	IDFT(ta,len);
	for(int i=0;i<ret.size();i++)ret[i]=ta[i];
	return ret;
}

}
ll m;
int main(){
	scanf("%d%lld",&n,&m),m%=(mod-1),jc[0]=ny[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n]=Power(jc[n],mod-2);
	for(int i=n-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	for(int i=0;i<=n;i++)scanf("%d",&a[i]);
	vector<int> A(n+1),B(n+1),C(n+1);
	for(int i=0;i<=n;i++)a[i]=1ll*jc[i]*a[i]%mod,A[i]=a[i];
	for(int i=0;i<=n;i++)B[i]=C[i]=ny[n-i];
	A=Conv::conv(A,B);
	for(int i=0;i<=n;i++)B[i]=A[i+n];
	for(int i=0;i<=n;i++)B[i]=1ll*B[i]*Power(mod-1,i)%mod*Power(Power(i+1,m),mod-2)%mod;
	C=Conv::conv(B,C);
	for(int i=0;i<=n;i++){
		int w=C[i+n];
		w=1ll*w*Power(mod-1,i)%mod*ny[i]%mod;
		cout<<w<<' ';
	}
}