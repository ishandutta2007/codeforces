#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[300005],m,q[300005],nd[300005],vst[300005],ans[10],cnt[300005];
void Try(int x){
	for(int i=n-x+1;i<=n;i++)q[i-(n-x)]=i;
	for(int i=1;i<=n-x;i++)q[i+x]=i;
	for(int i=1;i<=n;i++)nd[q[i]]=p[i],vst[i]=0;
	int s=0;
	for(int i=1;i<=n;i++){
		if(vst[i])continue;
		int cnt=1,tmp=i;
		vst[i]=1;
		while(nd[tmp]!=i)cnt++,tmp=nd[tmp],vst[tmp]=1;
		s+=cnt-1;
	}
	if(s<=m)ans[++ans[0]]=x;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m,ans[0]=0;
		for(int i=0;i<n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)cnt[(i-p[i]+n)%n]++;
		for(int i=0;i<n;i++)if(cnt[i]>=n/3)Try(i);
		cout<<ans[0]<<' ';
		for(int i=1;i<=ans[0];i++)cout<<ans[i]<<' ';
		puts("");
	}
}