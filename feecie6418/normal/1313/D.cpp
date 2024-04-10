#include<bits/stdc++.h>
using namespace std;
int n,m,K,f[256],p[10],tot,ans=-1e9;
struct Thing{
	int pos,id;
	bool operator <(const Thing j) const {
		return pos!=j.pos?pos<j.pos:id<j.id;
	}
}a[200005];
int main() {
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,l,r;i<=n;i++)scanf("%d%d",&l,&r),a[++tot]={l,i},a[++tot]={r+1,-i};
	sort(a+1,a+tot+1);
	memset(f,0xc0,sizeof(f)),f[0]=0;
	for(int i=1;i<=tot;i++){
		int len=(i==tot?0:a[i+1].pos-a[i].pos);
		if(a[i].id>0){
			int k=0;
			for(int j=1,f=0;j<=K&&!f;j++)if(!p[j])p[j]=a[i].id,k=j-1,f=1;
			for(int j=(1<<K)-1;j>=0;j--)f[j]=max(f[j],f[(j&(1<<k))?j-(1<<k):j])+(__builtin_popcount(j)&1)*len;
		}
		else {
			int k=0;
			for(int j=1,f=0;j<=K&&!f;j++)if(p[j]+a[i].id==0)p[j]=0,k=j-1,f=1;
			for(int j=0;j<(1<<K);j++)if(j&(1<<k))f[j]=-1e9;else f[j]=max(f[j],f[j+(1<<k)])+(__builtin_popcount(j)&1)*len;
		}
	}
	for(int i=0;i<(1<<K);i++)ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}