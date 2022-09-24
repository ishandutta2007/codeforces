
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int mod=998244353;
int n,K,a[500005],b[500005],hv[500005],pos[500005];
void Solve(){
	cin>>n>>K;
	for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i,hv[i]=0;
	int ans=1;
	for(int i=1;i<=K;i++){
		cin>>b[i],hv[pos[b[i]]]=i;
	}
	for(int i=1;i<=K;i++){
		int t=0;
		if(pos[b[i]]>1&&hv[pos[b[i]]-1]<i)t=ans;
		if(pos[b[i]]<n&&hv[pos[b[i]]+1]<i)t=(t+ans)%mod;
		ans=t;
		//cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)pos[i]=hv[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
    return 0;
}