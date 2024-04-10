#include <bits/stdc++.h>
int n,m,a[2000005],cnt,vis[2000005],l[2000005],r[2000005],d[2000005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&l[i],&r[i]);r[i]=r[i]+l[i]-1;
		if (r[i]>r[a[l[i]]])a[l[i]]=i;
		d[l[i]]++;d[r[i]+1]--;
	}for(int i=1;i<=n;++i)d[i]+=d[i-1];
	int max=0,pre=0;
	for(int i=1;i<=n;++i){
		if (r[a[i]]>r[pre])pre=a[i];
		if (max<i&&d[i]){
			//printf(">%d %d\n",i,pre);
			max=r[pre];
			vis[pre]=1;
			cnt++;
		}
	}printf("%d\n",m-cnt);
	for(int i=1;i<=m;++i)if(!vis[i])printf("%d ",i);
	return 0;
}