#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,g=3,invg=(mod+1)/g;
typedef long long ll;
int n,m=0,cnt1=0,cnt2=0;
char a[105];
int ta[300005],tb[300005],ny[300005],jc[300005],tr[300005],wk[300005],ans=0;
int Power(int x,int y){
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
void NTT(int a[],int n,int flag){
	for(int i=0;i<n;i++)if(tr[i]<i)swap(a[i],a[tr[i]]);
	for(int i=1;i<n;i<<=1){
		int w=Power(flag==1?g:invg,(mod-1)/(i<<1));
		wk[0]=1;
		for(int j=1;j<i;j++)wk[j]=1ll*wk[j-1]*w%mod;
		for(int j=0;j<n;j+=(i<<1)){
			for(int k=0;k<i;k++){
				int t=1ll*wk[k]*a[i+j+k]%mod;
				a[i+j+k]=(a[j+k]-t+mod)%mod,a[j+k]=(a[j+k]+t)%mod;
			}
		}
	}
	if(flag==-1)for(int i=0,t=Power(n,mod-2);i<n;i++)a[i]=1ll*a[i]*t%mod;
}
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main(){
	cin>>n;
	bool allwb=1,allbw=1,allwbbw=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%s",a);
		if(a[0]=='W'&&a[1]=='W')m--,allwb=0,allbw=0,allwbbw=0;
		if(a[0]=='B'&&a[1]=='B')m++,allwb=0,allbw=0,allwbbw=0;
		if(a[0]=='B'&&a[1]=='?')m++,cnt1++,allwb=0;
		if(a[0]=='?'&&a[1]=='B')m++,cnt1++,allbw=0;
		if(a[0]=='W'&&a[1]=='?')cnt1++,allbw=0;
		if(a[0]=='?'&&a[1]=='W')cnt1++,allwb=0;
		if(a[0]=='?'&&a[1]=='?')cnt2++,cnt++;
		if(a[0]=='B'&&a[1]=='W')allwb=0;
		if(a[0]=='W'&&a[1]=='B')allbw=0;
	}
	jc[0]=ny[0]=1;
	for(int i=1;i<=300000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[300000]=Power(jc[300000],mod-2);
	for(int i=300000-1;i>=1;i--)ny[i]=1ll*(i+1)*ny[i+1]%mod;
	ans=C(cnt1+2*cnt2,m+cnt2);
	if(allwbbw)ans=(ans-Power(2,cnt)+mod)%mod;
	if(allwb)ans=(ans+1)%mod;
	if(allbw)ans=(ans+1)%mod;
	cout<<ans;
}