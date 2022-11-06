#include<bits/stdc++.h>
#define N 55
using namespace std;
typedef long long LL;
int used[N],Next[N],a[N];char s[N];
LL F[N][N][2],tmp[N][2],ans;int n,m;
void clear(){
	for (int i=0;i<=n;i++)
		for (int k=0;k<m;k++)
			F[i][k][0]=F[i][k][1]=0;
}
void dp(int st,int ed){
	for (int i=st;i<=ed;i++)
		for (int k=0;k<m;k++)
			for (int ok=0;ok<2;ok++)
				if (F[i-1][k][ok]){
					for (int cur=0;cur<2;cur++){
						if (used[i]!=-1&&used[i]!=cur) continue;
						int j=k;
						for (;j&&a[j+1]!=cur;j=Next[j]);
						j+=a[j+1]==cur;
						if (j==m) F[i][0][1]+=F[i-1][k][ok];
							 else F[i][j][ok]+=F[i-1][k][ok];
					}
				}
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);m=strlen(s+1);
	for (int i=1;i<=m;i++)
		a[i]=s[i]-'0';
	for (int i=2,j=0;i<=m;i++){
		for (;j&&a[j+1]!=a[i];j=Next[j]);
		Next[i]=(j+=a[j+1]==a[i]);
	}
	for (int i=1;i<=n;i++) used[i]=-1;
	clear();F[0][0][0]=1;dp(1,n);
	for (int k=0;k<m;k++)
		ans+=F[n][k][1];
	for (int len=1;len<m;len++){
		for (int i=1;i<=n;i++) used[i]=-1;
		for (int i=1;i<=len;i++)
			used[n-len+i]=a[i];
		for (int i=len+1;i<=m;i++)
			used[i-len]=a[i];
		clear();F[n-len+1][0][0]=1;
		dp(n-len+2,n);
		for (int k=0;k<m;k++)
			for (int ok=0;ok<2;ok++) 
				tmp[k][ok]=F[n][k][ok];
		clear();
		for (int k=0;k<m;k++)
			for (int ok=0;ok<2;ok++)
				F[0][k][ok]=tmp[k][ok];
		dp(1,n);
		for (int k=0;k<m;k++)
			ans+=F[n][k][0];
	}
	printf("%lld\n",ans);
}