#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,inf=2e9;
int n,a[500005],ans=0,f1[500005],f2[500005],f3[500005],f4[500005];
void Solve(){
	int p=max_element(a+1,a+n+1)-a;
	if(p==1)return ;
	f1[n]=-inf;
	for(int i=n-1;i>=p;i--){
		f1[i]=inf;
		if(a[i]>a[i+1])f1[i]=min(f1[i],f1[i+1]);
		if(a[i]>f1[i+1])f1[i]=min(f1[i],a[i+1]);
	}
	if(f1[p]==inf)return ;
	f2[1]=-inf;
	for(int i=2;i<p;i++){
		f2[i]=inf;
		if(a[i]>a[i-1])f2[i]=min(f2[i],f2[i-1]);
		if(a[i]>f2[i-1])f2[i]=min(f2[i],a[i-1]);
	}
	f3[p-1]=f1[p];
	if(a[p-1]>f1[p])f4[p-1]=inf;
	else f4[p-1]=-inf;
	for(int i=p-2;i>=1;i--){
		f3[i]=inf,f4[i]=-inf;
		if(a[i]>a[i+1])f4[i]=max(f4[i],f4[i+1]);
		if(a[i]>f3[i+1])f4[i]=max(f4[i],a[i+1]);
		if(a[i]<a[i+1])f3[i]=min(f3[i],f3[i+1]);
		if(a[i]<f4[i+1])f3[i]=min(f3[i],a[i+1]);
	}
	for(int i=1;i<p;i++)ans+=(f4[i]>f2[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	Solve(),reverse(a+1,a+n+1),Solve();
	cout<<ans;
}