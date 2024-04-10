#include<bits/stdc++.h>
using namespace std;
int n,dfn[500005],h[500005],cnt,a[500005],b[500005],w[500005];
int ans[500005],s[500005],f[500005],vst[500005],F,s1,s2,g[500005];
struct E{
	int to,next;
}e[2000005];
void Clear(){
	for(int i=1;i<=cnt;i++)e[i].to=e[i].next=0;
	cnt=0;
	for(int i=1;i<=2*n;i++){
		h[i]=ans[i]=s[i]=f[i]=vst[i]=w[i]=0;
	}
}
void A(int x,int y){
	e[++cnt]={y,h[x]};
	h[x]=cnt;
}
int ops(int x){
	return x>n?x-n:x+n;
}
void dfs(int x,int fr){
	vst[x]=fr,s1++;
	if(vst[ops(x)]==fr)F=1;
	if(x<=n)s2++;
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(!vst[y])dfs(y,fr);
	}
} 
void dfs2(int x,int f){
	w[x]=1;
	if(x<=n){if(!f)ans[x]=1;else ans[x]=0;}
	if(x>n){if(f)ans[x-n]=1;else ans[x-n]=0;}
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(!w[y])dfs2(y,f);
	}
} 
int main(){
	int T;
	cin>>T;
	while(T--){
		int sum=0;
		cin>>n,F=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[a[i]]++,ans[i]=-1;
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),s[b[i]]++;
		bool flag=0;
		for(int i=1;i<=n;i++)if(s[i]!=2)flag=1;
		if(flag){
			puts("-1"),Clear();
			continue;
		}
		for(int i=1;i<=n;i++)f[i]=0;
		for(int i=1;i<=n;i++)if(!f[a[i]])f[a[i]]=i,g[a[i]]=1;
		for(int i=1;i<=n;i++)if(!f[b[i]])f[b[i]]=i,g[b[i]]=2;
		for(int i=1;i<=n;i++){
			if(i==f[a[i]])continue;
			A(i,f[a[i]]+n),A(i+n,f[a[i]]);
			A(f[a[i]]+n,i),A(f[a[i]],i+n);
		}
		for(int i=1;i<=n;i++){
			if(i==f[b[i]])continue;
			if(g[b[i]]==1){
				A(i,f[b[i]]),A(f[b[i]],i),A(i+n,f[b[i]]+n),A(f[b[i]]+n,i+n);
			}
			else {
				A(i,f[b[i]]+n),A(i+n,f[b[i]]);
				A(f[b[i]]+n,i),A(f[b[i]],i+n);
			}
		}
		for(int i=1;i<=n;i++){
			if(vst[i]||~ans[i])continue;
			s1=s2=0,dfs(i,i);
			if(F)break;
			if(s2<s1-s2)dfs2(i,0);
			else dfs2(i,1);
			sum+=min(s2,s1-s2);
		}
		if(F){
			puts("-1"),Clear();
			continue;
		}
		cout<<sum<<endl;
		for(int i=1;i<=n;i++)if(ans[i]==1)printf("%d ",i);
		puts("");
		Clear();
	}
	return 0;
}