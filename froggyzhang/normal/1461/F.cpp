#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int inf=1e8;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],len;
char s[5];
int ok[3],tot;
struct Data{
	int l,r,t,x;
}g[N];
int dp[155],pre[155];
void dfs(int u){
	if(!u)return;
	dfs(pre[u]);
	if(pre[u]==u-1&&g[u].t==1){
		for(int i=g[u].l;i<=g[u].r;++i){
			putchar('1');
			if(i<g[u].r)putchar('+');
		}
	}
	else{
		for(int i=g[pre[u]+1].l;i<=g[u].r;++i){
			printf("%d",a[i]);
			if(i<g[u].r)putchar('*');
		}
	}
	if(u^tot)putchar('+');
}
void Solve(int l,int r){
	tot=0;
	for(int i=l;i<=r;++i){
		if(a[i]==1){
			++tot;
			g[tot].l=i;
			while(i<r&&a[i+1]==1)++i;
			g[tot].r=i;
			g[tot].t=1;
			g[tot].x=g[tot].r-g[tot].l+1;		
		}
		else{
			++tot;
			g[tot].l=i,g[tot].x=a[i];
			while(i<r&&a[i+1]!=1)++i,g[tot].x=min(g[tot].x*a[i],inf);
			g[tot].r=i;
			g[tot].t=2;	
		}
	}
	int tmp=1;
	for(int i=1;i<=tot;++i){
		if(g[i].t==2)tmp=min(1LL*inf,1LL*tmp*g[i].x);
	}
	if(tmp==inf){
		int L=1,R=tot;
		while(g[L].t==1)++L;
		while(g[R].t==1)--R;
		for(int i=1;i<L;++i){
			for(int j=g[i].l;j<=g[i].r;++j){
				putchar('1');
				putchar('+');	
			}
		}
		for(int i=L;i<=R;++i){
			for(int j=g[i].l;j<=g[i].r;++j){
				printf("%d",a[j]);
				if(j<r)putchar(j==g[R].r?'+':'*');	
			}
		}
		for(int i=R+1;i<=tot;++i){
			for(int j=g[i].l;j<=g[i].r;++j){
				putchar('1');
				if(j<r)putchar('+');
			}
		}
	}
	else{
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=tot;++i){
			if(g[i].t==1)dp[i]=dp[i-1]+g[i].x,pre[i]=i-1;
			int num=(g[i].t==1?1:g[i].x);
			for(int j=i-1;j>=0;--j){
				if(dp[j]+num>dp[i]){
					dp[i]=dp[j]+num;
					pre[i]=j;
				}
				num*=(g[j].t==1?1:g[j].x);		
			}
		}
		dfs(tot);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;++i){
		if(s[i]=='*')ok[2]=1;
		else if(s[i]=='+')ok[0]=1;
		else ok[1]=1;
	}
	if(len==1){
		for(int i=1;i<=n;++i){
			printf("%d%c",a[i],i==n?'\n':s[1]);
		}
	}
	else if(ok[2]){
		if(ok[0]){
			for(int i=1,las=0;i<=n;++i){
				if(a[i]&&(i==n||!a[i+1])){
					Solve(las+1,i);	
					if(i<n)putchar('+');
				}
				else if(!a[i]){
					las=i;
					putchar('0');
					if(i<n)putchar('+');
				}
			}
		}
		else{
			for(int i=1;i<=n;++i){
				printf("%d%c",a[i],i==n?'\n':(!a[i+1]?'-':'*'));
			}	
		}
	}
	else{
		for(int i=1;i<=n;++i){
			printf("%d%c",a[i],i==n?'\n':'+');
		}	
	}
	return 0;
}