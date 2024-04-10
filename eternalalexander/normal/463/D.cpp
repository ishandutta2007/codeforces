#include <bits/stdc++.h>
int p[10][1005],q[10][1005],n,k,ans,f[1005];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j){
			scanf("%d",&p[i][j]);
			q[i][p[i][j]]=j;
		}
//	assert(q[2][1]>q[2][4]);
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			int flag=1;
			for(int l=2;l<=k;++l)
				if (q[l][p[1][j]]>q[l][p[1][i]]){flag=0;break;}
			if (flag)f[i]=std::max(f[i],f[j]+1);
		}//printf("%d ",f[i]);
		ans=std::max(ans,f[i]);
	}printf("%d",ans);
	return 0;
}