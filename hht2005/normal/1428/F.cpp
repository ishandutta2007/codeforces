#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
char s[maxn];
int l[maxn],r[maxn],p[maxn][20],Log[maxn],cnt,n;
int Max(int l,int r) {
	if(l>r)return 0;
	int L=Log[r-l+1];
	return max(p[l][L],p[r-(1<<L)+1][L]);
}
int f(int L,int R) {
	if(L>cnt||l[L]>R)return 0;
	int t=lower_bound(r+1,r+cnt+1,R)-r,v=Max(L,t-1);
	if(s[R]=='1')return max(v,R-l[t]+1);
	else return v;
}
int calc(int x) {
	int t=lower_bound(r+1,r+cnt+1,x-1)-r,v=r[t]-x+1,L=x,R=n;
	while(L<=R) {
		int mid=(L+R)>>1;
		if(f(t+1,mid)<=v)L=mid+1;
		else R=mid-1;
	}
	return L-x+1;
}
int main() {
	long long sum=0,ans=0;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) {
		while(i<=n&&s[i]=='0')i++;
		if(i>n)break;
		l[++cnt]=i;
		while(i<=n&&s[i]=='1')i++,p[cnt][0]++;
		r[cnt]=i-1;
	}
	for(int i=2;i<=n;i++)
		Log[i]=Log[i/2]+1;
	for(int j=1;1<<j<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			p[i][j]=max(p[i][j-1],p[i+(1<<(j-1))][j-1]);
	int Max=0;
	for(int i=1;i<=cnt;i++) {
		sum+=1ll*Max*(l[i]-r[i-1]-1);
		for(int j=l[i];j<=r[i];j++)sum+=max(Max,j-l[i]+1);
		Max=max(Max,r[i]-l[i]+1);
	}
	sum+=1ll*Max*(n-r[cnt]);
	ans=sum;
	for(int i=2;i<=n;i++) {
		if(s[i-1]=='1')sum-=calc(i);
		ans+=sum;
	}
	printf("%lld\n",ans);
	return 0;
}