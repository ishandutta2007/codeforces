#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long son[1000001],Last[1000001],Next[1000001],num[1000001],tot;
long long fa[500001],rl[500001],sum1,maxx,l,r;
long long dl[500001],ans=1e9,bj[500001];
void fason(int a,int b,int c) {
	Next[++tot]=Last[a];
	Last[a]=tot;
	son[tot]=b;
	num[tot]=c;
}
void dfs(int x,int sum) {
	for(int i=Last[x];i;i=Next[i])
		if(son[i]!=fa[x]) {
			fa[son[i]]=x;
			rl[son[i]]=num[i];
			dfs(son[i],sum+num[i]);
	}
    if(maxx<sum) {
		maxx=sum;
		sum1=x;
	}
}
long long dfs1(int x,int fa,int sum) {
	long long maxx=0;
	for(int i=Last[x];i;i=Next[i])
		if(son[i]!=fa&&bj[son[i]]==0)
			maxx=max(maxx,dfs1(son[i],x,sum+num[i])+num[i]);
	return maxx;
}
int main() {
	int n,s,a,b,c;
	scanf("%d%d",&n,&s);
	for(int i=2;i<=n;i++) {
		scanf("%d%d%d",&a,&b,&c);
		fason(a,b,c);
		fason(b,a,c);
	}
	dfs(1,0);
	maxx=0;
	memset(fa,0,sizeof(fa));
	l=sum1;
	dfs(l,0);
	r=sum1;
	long long h=1,e=1,sum=0,fsum=0,ssum=0;
	for(int i=r;fa[i];i=fa[i])
		ssum+=rl[i];
	dl[1]=r;
	int cnt=1;
	for(int i=r;fa[i];i=fa[i]) {
		bj[i]=1;
		if(cnt<s) {
			dl[++e]=fa[i];
			sum+=rl[i];
			cnt++;
		}
		else {
			ans=min(ans,max(ssum-sum-fsum,fsum));
			cnt++;
			sum+=rl[i];
			dl[++e]=fa[i];
			while(cnt>s) {
				sum-=rl[dl[h]];
				fsum+=rl[dl[h++]];
				cnt--;
			}
		}
	}
	ans=min(ans,max(ssum-sum-fsum,fsum));
	bj[l]=1;
	for(int i=r;i;i=fa[i])
		ans=max(ans,dfs1(i,0,0));
	cout<<ans<<endl;
	return 0;
}