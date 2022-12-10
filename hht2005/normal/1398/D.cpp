#include<bits/stdc++.h>
using namespace std;
int f[210][210][210],r[210],g[210],b[210];
int main() {
	int R,G,B,ans=0;
	scanf("%d%d%d",&R,&G,&B);
	for(int i=1;i<=R;i++)scanf("%d",r+i);
	for(int i=1;i<=G;i++)scanf("%d",g+i);
	for(int i=1;i<=B;i++)scanf("%d",b+i);
	sort(r+1,r+R+1,greater<int>());
	sort(g+1,g+G+1,greater<int>());
	sort(b+1,b+B+1,greater<int>());
	for(int i=0;i<=R;i++)
		for(int j=0;j<=G;j++)
			for(int k=0;k<=B;k++) {
				if(i&&j)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+r[i]*g[j]);
				if(i&&k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+r[i]*b[k]);
				if(j&&k)f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+g[j]*b[k]);
				ans=max(ans,f[i][j][k]);
			}
	printf("%d\n",ans);
	return 0;
}