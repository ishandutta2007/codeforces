#include <bits/stdc++.h>
#define MAXN 1010
#define LL long long
using namespace std;

const LL P=998244353;

int n,m,sx,sy;
int a[MAXN][MAXN];
pair<int,pair<LL,LL> > v[MAXN*MAXN];
int pre[MAXN*MAXN];
LL s1[MAXN*MAXN],s2[MAXN*MAXN],s3[MAXN*MAXN],s4[MAXN*MAXN];
LL f[MAXN*MAXN],sf[MAXN*MAXN];
LL inv[MAXN*MAXN];

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d%d",&sx,&sy);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			v[(i-1)*m+j]=make_pair(a[i][j],make_pair(i,j));
	sort(v+1,v+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(v[i-1].first!=v[i].first) pre[i]=i-1;
		else pre[i]=pre[i-1];
		s1[i]=(s1[i-1]+v[i].second.first)%P;
		s2[i]=(s2[i-1]+v[i].second.first*v[i].second.first)%P;
		s3[i]=(s3[i-1]+v[i].second.second)%P;
		s4[i]=(s4[i-1]+v[i].second.second*v[i].second.second)%P;
	}
	inv[1]=1;
	for(int i=2;i<=n*m;i++) inv[i]=(P-P/i)*inv[P%i]%P;
	for(int i=1;i<=n*m;i++){
		if(!pre[i]){
			f[i]=0;
			continue;
		}
		int c=pre[i];
		LL temp=(sf[pre[i]]+s2[pre[i]]+s4[pre[i]]-(s1[pre[i]]*v[i].second.first%P+s3[pre[i]]*v[i].second.second%P)*2)%P;
		temp=(temp*inv[c]%P+v[i].second.first*v[i].second.first+v[i].second.second*v[i].second.second)%P;
		f[i]=(temp+P)%P;
		sf[i]=(sf[i-1]+f[i])%P;
	}
	for(int i=1;i<=n*m;i++)
		if(v[i].second.first==sx && v[i].second.second==sy){
			cout<<f[i]<<endl;
			return 0;
		}
}