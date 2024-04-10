#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7,inf=1e9;
ll a[200005];
int n,f[60][200005],I;
void upd(int &x,int y){
	x=min(x,y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	{
		ll x=*max_element(a+1,a+n+1);
		for(int i=1;i<=n;i++)a[i]=x-a[i];
	}
	memset(f,0x3f,sizeof(f));
	int s=0;
	for(int i=1;i<=n;i++)s+=(a[i]&1);
	upd(f[0][0],s),upd(f[0][s],n-s);
	for(int i=1;i<=59;i++){
		I=i;
		stable_sort(a+1,a+n+1,[](ll x,ll y){return (x&((1ll<<I)-1))>(y&((1ll<<I)-1));});
		int c1=0,c2=0;
		for(int j=1;j<=n;j++)c2+=((a[j]>>i)&1);
		for(int j=0;j<=n;j++){
			if(j&&((a[j]>>i)&1))c2--,c1++;
			upd(f[i][c1],f[i-1][j]+c2+(j-c1));
			upd(f[i][c2+j],f[i-1][j]+c1+(n-j-c2));
		}
	}
	for(int i=0;i<=n;i++)f[59][i]+=i;
	cout<<*min_element(f[59],f[59]+n+1);
}