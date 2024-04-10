#include<stdio.h>
int n;
int prv[200002],nxt[200001];
int a[200001];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n ;i++){
		scanf("%d",a+i);
		nxt[i]=i+1;
		prv[i]=i-1;
	}
	int cur=1;
	int ans=n;
	while(nxt[cur]!=n+1){
		
		if(a[cur]!=a[nxt[cur]]){
			cur=nxt[cur];
			continue;
		}
		a[cur]++;
		nxt[cur]=nxt[nxt[cur]];
		prv[nxt[cur]]=cur;
		if(cur!=1) cur=prv[cur];
		ans--;
	}
	printf("%d\n",ans);
	cur=1;
	while(cur!=n+1){
		printf("%d ",a[cur]);
		cur=nxt[cur];
	}
}