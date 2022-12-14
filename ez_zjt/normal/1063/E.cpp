#include <bits/stdc++.h>
#define MAXN 1010

int n;
int a[MAXN];
int b[MAXN];
char ans[MAXN][MAXN];

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	scanf("%d",&n);
	bool flag=0;
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		if(t!=i) flag=1;
		b[t]=i;
	}
	if(!flag){
		printf("%d\n",n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) putchar('.');
			puts("");
		}
		return 0;
	}
	for(int i=1;i<=n;i++) a[i]=i;
	int cur=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]='.';
	for(int i=1;i<=n;i++)
		if(b[i]!=i){
			for(int j=1;j<i;j++) a[j]=-1;
			ans[cur][i]='\\';
			ans[cur][b[i]]='\\';
			cur++;
			a[i]=0;
			a[b[i]]=-1;
			break;
		}
	while(1){
		int t;
		for(int i=1;i<=n;i++) if(!a[i]) t=i;
		if(cur&1){
			int p=0;
			for(int i=1;i<=n;i++)
				if(a[i]!=-1){
					if(b[a[i]]==i) a[i]=-1;
					else{
						p=i;
						break;
					}
				}
			if(!a[p]) break;
			int x=a[p];
			if(b[x]==t){
				ans[cur][p]='\\';
				ans[cur][t]='\\';
				a[t]=-1;
				a[p]=0;
			}else{
				ans[cur][p]=ans[cur][b[x]]=ans[cur][t]='\\';
				a[t]=a[b[x]];
				a[b[x]]=-1;
				a[p]=0;
			}
			cur++;
		}else{
			int p=0;
			for(int i=n;i>=1;i--)
				if(a[i]!=-1){
					if(b[a[i]]==i) a[i]=-1;
					else{
						p=i;
						break;
					}
				}
			if(!a[p]) break;
			int x=a[p];
			if(b[x]==t){
				ans[cur][p]='/';
				ans[cur][t]='/';
				a[t]=-1;
				a[p]=0;
			}else{
				ans[cur][p]=ans[cur][b[x]]=ans[cur][t]='/';
				a[t]=a[b[x]];
				a[b[x]]=-1;
				a[p]=0;
			}
			cur++;
		}
	}
	printf("%d\n",n-1);
	for(int i=1;i<=n;i++) puts(ans[i]+1);
}