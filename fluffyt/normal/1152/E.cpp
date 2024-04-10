#include<bits/stdc++.h>
using namespace std;
const int MX=200000;
int n,m,tot,totv,len,root,cntr,a[200005],b[200005];
int vis[200005],head[200005],used[400005],cnt[200005];
int point[200005],nxt[400005],route[200005],val[200005];
int all[200005],self[200005];
int getinv(int x)
{
	return x&1?x+1:x-1;
}
void dfs(int x)
{
	vis[x]=1;
	for(int &i=head[x];i;i=nxt[i])
	{
		if(!used[i])
		{
			int y=point[i];
			used[i]=used[getinv(i)]=1;
			dfs(y);
		}
	}
	route[++len]=x;
	while(self[x]) route[++len]=x,self[x]--;  
}
void addedge(int x,int y)
{
	point[++tot]=y,nxt[tot]=head[x],head[x]=tot;
	point[++tot]=x,nxt[tot]=head[y],head[y]=tot;
}
void bad() 
{
	puts("-1");
	exit(0);
}
int main()
{
	scanf("%d",&n);
	n--;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),all[++totv]=a[i];
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),all[++totv]=b[i];
	sort(all+1,all+1+totv);
	totv=unique(all+1,all+1+totv)-all-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i]) bad();
		int v1=lower_bound(all+1,all+1+totv,a[i])-all,
			v2=lower_bound(all+1,all+1+totv,b[i])-all;
		val[v1]=a[i],val[v2]=b[i];
		if(v1!=v2) addedge(v1,v2),cnt[v1]++,cnt[v2]++;
		else self[v1]++;
	}
	for(int i=1;i<=totv;i++) if(cnt[i]&1) root=i,cntr++;
	if(cntr>2||totv>n+1) bad();
	if(!root) root=1;
	dfs(root);
	if(len!=n+1) bad();
	for(int i=len;i>=1;i--) printf("%d ",val[route[i]]);
	return 0;
}