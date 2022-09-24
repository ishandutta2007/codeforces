#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,g=3,invg=(mod+1)/g; 
int jc[200005]={1},ny[200005]={1},a[600005],b[600005],tr[600005],wk[600005],n,m;
int C(int x,int y){
	if(x<y)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
void NTT(int a[],int n,int fl){
	for(int i=0;i<n;i++)if(i<tr[i])swap(a[i],a[tr[i]]);
	for(int i=1;i<n;i<<=1){
		int w=Power(fl==1?g:invg,(mod-1)/(i<<1));
		wk[0]=1;
		for(int j=1;j<i;j++)wk[j]=1ll*wk[j-1]*w%mod;
		for(int j=0;j<n;j+=(i<<1)){
			int *p=a+j,*q=a+i+j,*t=wk;
			for(int k=0;k<i;k++,++p,++q,++t){
				int x=*p,y=1ll*(*q)*(*t)%mod,z=x;
				x+=y,((x>=mod)&&(x-=mod)),*p=x;
				x=z-y,((x<0)&&(x+=mod)),*q=x;
			}
		}
	}
	if(fl==-1){
		int inv=Power(n,mod-2);
		for(int i=0;i<n;i++)a[i]=1ll*a[i]*inv%mod;
	}
}
vector<int> GetS2(int n){
	for(int i=0;i<=n;i++){
		if(i&1)a[i]=mod-ny[i];
		else a[i]=ny[i];
		b[i]=1ll*Power(i,n)*ny[i]%mod;
	}
	int len=1;
	while(len<=2*n)len<<=1;
	for(int i=0;i<len;i++)tr[i]=(tr[i>>1]>>1)|((i&1)?(len>>1):0);
	NTT(a,len,1),NTT(b,len,1);
	for(int i=0;i<len;i++)a[i]=1ll*a[i]*b[i]%mod;
	NTT(a,len,-1);
	vector<int> ans(n+1);
	for(int i=0;i<=n;i++)ans[i]=a[i];
	for(int i=0;i<len;i++)a[i]=b[i]=0;
	return ans;
}
vector<int> S2[200005];
int ans[200005];
int main(){
	for(int i=1;i<=200000;i++)jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
	cin>>n>>m,m=min(m,n);
	if(m==1)return puts("1"),0;
	for(int i=1;i<=n;i++)if(!S2[(n+i-1)/i].size())S2[(n+i-1)/i]=GetS2((n+i-1)/i);
	int s=0;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=m&&j<=(n+i-1)/i;j++)ans[i]=(ans[i]+S2[(n+i-1)/i][j])%mod;
		for(int j=i+i;j<=n;j+=i)ans[i]=(ans[i]-ans[j]+mod)%mod;
		if(n%i)ans[i]=(ans[i]-ans[n]+mod)%mod;
		//cout<<i<<' '<<ans[i]<<'\n';
	}
	cout<<ans[1];
}