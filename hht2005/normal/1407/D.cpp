#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int h[maxn],sk1[maxn],sk2[maxn],f[maxn],jp[maxn][4],r1,r2;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",h+i);
	sk1[r1=1]=sk2[r2=1]=1;
	for(int i=2;i<=n;i++) {
		while(r1&&h[i]>=h[sk1[r1]])jp[sk1[r1--]][0]=i;
		while(r2&&h[i]<=h[sk2[r2]])jp[sk2[r2--]][1]=i;
		sk1[++r1]=i;
		sk2[++r2]=i;
	}//sadfvc
	sk1[r1=1]=sk2[r2=1]=n;
	for(int i=n-1;i>=1;i--) {
		while(r1&&h[i]>=h[sk1[r1]])jp[sk1[r1--]][2]=i;
		while(r2&&h[i]<=h[sk2[r2]])jp[sk2[r2--]][3]=i;
		sk1[++r1]=i;
		sk2[++r2]=i;
	}
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	if(jp[1][0])f[jp[1][0]]=1;
	if(jp[1][1])f[jp[1][1]]=1;
	for(int i=2;i<=n;i++) {
		f[i]=min(f[i],min(f[jp[i][2]],f[jp[i][3]])+1);
		if(jp[i][0])f[jp[i][0]]=min(f[jp[i][0]],f[i]+1);
		if(jp[i][1])f[jp[i][1]]=min(f[jp[i][1]],f[i]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}