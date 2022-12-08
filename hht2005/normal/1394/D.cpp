#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<int>S[N];
int w[N],a[N];
long long f[N][2];
void dfs(int x,int fa) {
	vector<long long>t;
	int cnt=0;
	long long sum=0;
	for(int y:S[x]) {
		if(y==fa)continue;
		dfs(y,x);
		cnt++;
		t.push_back(f[y][1]-f[y][0]);
		sum+=f[y][0];
	}
	f[x][0]=1ll*max(cnt,1)*w[x]+sum;
	f[x][1]=1ll*(cnt+1)*w[x]+sum;
	sort(t.begin(),t.end());
	for(int i=1;i<=cnt;i++) {
		sum+=t[i-1];
		f[x][0]=min(f[x][0],sum+1ll*max(i+1,cnt-i)*w[x]);
		f[x][1]=min(f[x][1],sum+1ll*max(i,cnt+1-i)*w[x]);
	}
	if(a[fa]>a[x])f[x][0]=1e12;
	if(a[fa]<a[x])f[x][1]=1e12;
}
int main() {
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		S[x].push_back(y);
		S[y].push_back(x);
	}
	vector<long long>t;
	int cnt=0;
	long long sum=0,ans=0;
	for(int y:S[1]) {
		dfs(y,1);
		cnt++;
		t.push_back(f[y][1]-f[y][0]);
		sum+=f[y][0];
	}
	ans=sum+1ll*cnt*w[1];
	sort(t.begin(),t.end());
	for(int i=1;i<=cnt;i++) {
		sum+=t[i-1];
		ans=min(ans,sum+1ll*max(i,cnt-i)*w[1]);
	}
	printf("%lld\n",ans);
	return 0;
}