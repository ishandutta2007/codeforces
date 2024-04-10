#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[100005],ans=0,fr[100005];
void Solve(){
	cin>>n,ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)fr[i]=-1e9;
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//	puts("");
	for(int i=1,lst=1;i<=n+1;i++){
		if(a[i]==a[lst])continue;
		if(i-lst<2)ans+=i-lst;
		else {
			int flag=0;
			if(fr[a[lst]]==-1e9)flag=1;
			else for(int k=fr[a[lst]]+1;k+1<lst;k++)if(a[k]!=a[lst]&&a[k+1]!=a[lst])flag=1;
			ans+=(flag?2:1);
			fr[a[lst]]=i-1;
		}
		lst=i;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)a[i]=0;
}
int main(){
	int t=1;
	while(t--)Solve();
	//while(1)Solve();
}