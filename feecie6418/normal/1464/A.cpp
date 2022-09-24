#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[100005],vst[100005];
int main() {
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(vst,0,sizeof(vst));
		cin>>n>>m;
		int ans=0;
		for(int i=1,x,y;i<=m;i++)cin>>x>>y,a[x]=y;
		for(int i=1;i<=n;i++){
			if(vst[i]||!a[i]||a[i]==i)continue;
			int p=i,cnt=0;
			while(a[p]&&!vst[a[p]])p=a[p],vst[p]=i,cnt++;
			//cout<<i<<' '<<cnt<<endl;
			if(a[p]==0||vst[a[p]]!=i)ans+=cnt;
			else ans+=cnt+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}