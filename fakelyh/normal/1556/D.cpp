#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans[500005],sum[500005],x,y;
signed main(){
	cin>>n>>k;
	for(register int i=2;i<=n;i++){
		cout<<"or "<<1<<' '<<i<<endl;
		cin>>x;
		cout<<"and "<<1<<' '<<i<<endl;
		cin>>y;
		sum[i]=x+y;
	}
	cout<<"or 2 3"<<endl;
	cin>>x;
	cout<<"and 2 3"<<endl;
	cin>>y;
	ans[3]=(sum[3]-sum[2]+x+y)>>1;
	ans[2]=(x+y-(sum[3]-sum[2]))>>1;
	ans[1]=sum[2]-ans[2];
	for(register int i=4;i<=n;i++)ans[i]=sum[i]-ans[1];
	sort(ans+1,ans+n+1);cout<<"finish "<<ans[k]<<endl;
	return 0;
}