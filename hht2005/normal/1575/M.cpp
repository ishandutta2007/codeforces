#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int f[N][N],x[N],w[N],sk[N],top;
char s[N][N];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	n++,m++;
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++)x[i]=-4000;
	for(int i=1;i<=n;i++) {
		top=0;
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='1')x[j]=i;
			w[j]=(i-x[j])*(i-x[j])+j*j;
			while(top>1&&1ll*(w[j]-w[sk[top]])*(sk[top]-sk[top-1])
						<=1ll*(w[sk[top]]-w[sk[top-1]])*(j-sk[top]))top--;
			sk[++top]=j;
		}
		int h=1;
		for(int j=1;j<=m;j++) {
			while(h<top&&w[sk[h+1]]-w[sk[h]]<=2*j*(sk[h+1]-sk[h]))h++;
			if(top)f[i][j]=(i-x[sk[h]])*(i-x[sk[h]])+(j-sk[h])*(j-sk[h]);
		}
	}
	for(int i=1;i<=m;i++)x[i]=8000;
	for(int i=n;i>=1;i--) {
		top=0;
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='1')x[j]=i;
			w[j]=(i-x[j])*(i-x[j])+j*j;
			while(top>1&&1ll*(w[j]-w[sk[top]])*(sk[top]-sk[top-1])
						<=1ll*(w[sk[top]]-w[sk[top-1]])*(j-sk[top]))top--;
			sk[++top]=j;
		}
		int h=1;
		for(int j=1;j<=m;j++) {
			while(h<top&&w[sk[h+1]]-w[sk[h]]<=2*j*(sk[h+1]-sk[h]))h++;
			if(top)f[i][j]=min(f[i][j],(i-x[sk[h]])*(i-x[sk[h]])+(j-sk[h])*(j-sk[h]));
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=f[i][j];
	printf("%lld\n",ans);
	return 0;
}