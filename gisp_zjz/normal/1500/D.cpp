#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,q,sum[1505],d[1505],ans[1505][1505];
int f[1505][1505][10],g[1505][1505][10],tmp[10],tmp2[10];
void comb(int c[],int a[],int b[]){
	if (a[0]==-1||b[0]==-1){
		c[0]=-1;
		for (int i=1;i<q;i++) c[i]=0;
		return;
	}
	int n=q,m=q,s=0,t=0;
	while (n>0&&a[n-1]==0) --n;
	while (m>0&&b[m-1]==0) --m;
	int tot=0;
	while (s<n||t<m){
		if (tot==q){
			c[0]=-1;
			for (int i=1;i<q;i++) c[i]=0;
			return;
		}
        if (s==n) c[tot++]=b[t++];
        else if (t==m) c[tot++]=a[s++];
        else if (a[s]<b[t]) c[tot++]=a[s++];
        else if (a[s]>b[t]) c[tot++]=b[t++];
        else c[tot++]=a[s++],t++;
	}
	for (int i=tot;i<q;i++) c[i]=0;
}
bool check(int x,int y,int sz,int k){
    int r=sz-(1<<k);
    comb(tmp,f[x][y],f[x][y+r]);
    comb(tmp2,tmp,f[x+r][y]);
    comb(tmp,tmp2,f[x+r][y+r]);
    return tmp[0]!=-1;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++) d[i]=d[i/2]+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&f[i][j][0]);
	for (int k=0;(1<<k)<=n;k++){
		memcpy(g,f,sizeof(f));
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (i+(1<<k)-1<n&&j+(1<<k)-1<n){
				comb(tmp,f[i][j],f[i][j+(1<<k)]);
				comb(tmp2,tmp,f[i+(1<<k)][j]);
				comb(g[i][j],tmp2,f[i+(1<<k)][j+(1<<k)]);
			} else if (i+(1<<k)-1<n){
				comb(g[i][j],f[i][j],f[i+(1<<k)][j]);
			} else if (j+(1<<k)-1<n){
				comb(g[i][j],f[i][j],f[i][j+(1<<k)]);
			}
			if (ans[i][j]==0&&g[i][j][0]==-1){
				int l=1<<k,r=min(2<<k,min(n-i+1,n-j+1)+1);
				while (r-l>1){
					int mid=(l+r)>>1;
					if (check(i,j,mid,k)) l=mid; else r=mid;
				}
				ans[i][j]=l;
			}
			if (ans[i][j]==0&&(i+(2<<k)-1>n||j+(2<<k)-1>n)){
				ans[i][j]=min(n-i+1,n-j+1);
			}
		}
		memcpy(f,g,sizeof(f));
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
		if (ans[i][j]==0) assert(0);
		ans[i][j]=min(ans[i][j],min(n-i+1,n-j+1));
		sum[ans[i][j]]++;
	}
	for (int i=n;i>1;i--) sum[i-1]+=sum[i];
	for (int i=1;i<=n;i++) printf("%d\n",sum[i]);
	return 0;
}