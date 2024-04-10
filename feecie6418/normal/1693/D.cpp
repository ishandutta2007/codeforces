#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int f0[200005],f1[200005],n,a[200005],R[200005];
ll ans=0;
void upd(int i){
	if(i>n)return R[i]=n,void();
	int lst0=f0[i],lst1=f1[i];
	f0[i]=-1e9,f1[i]=1e9;
	if(a[i]>a[i-1])f0[i]=max(f0[i],f0[i-1]);
	if(a[i]<a[i-1])f1[i]=min(f1[i],f1[i-1]);
	if(a[i]>f1[i-1])f0[i]=max(f0[i],a[i-1]);
	if(a[i]<f0[i-1])f1[i]=min(f1[i],a[i-1]);
	if(f0[i]==lst0&&f1[i]==lst1)return ;
	//cout<<i<<' '<<f0[i]<<' '<<f1[i]<<' '<<R[i]<<'\n';
	if(f0[i]<0&&f1[i]>n)return R[i]=i-1,void();
	upd(i+1),R[i]=R[i+1];
	//cout<<i<<' '<<R[i]<<'\n';
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		f0[i]=1e9,f1[i]=-1e9;
		upd(i+1),R[i]=R[i+1];
		ans+=R[i]-i+1;
	}
	cout<<ans;
}