#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,a[200005],pre[200005],suf[200005];
void Solve(){
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt+=(i>1&&a[i]==a[i-1]);
	if(cnt<=1){
		puts("0");
		return ;
	}
	pre[1]=suf[n]=0;
	pre[0]=suf[n+1]=0;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]&&!pre[i-1])pre[i]=i;
		else pre[i]=pre[i-1];
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]==a[i+1]&&!suf[i+1])suf[i]=i;
		else suf[i]=suf[i+1];
	}
	int ans=1e9;
	for(int i=2;i<=n;i++){
		int u=1;
		if(pre[i-2])u+=(i-1)-pre[i-2];
		if(suf[i+1])u+=suf[i+1]-i;
		ans=min(ans,u);
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}