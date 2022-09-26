#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
typedef long long ll;
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
int n,m,a[N],las[22],s[22][N],t[1<<22],b[22][22],g[22],ans,T,lim,all;
char ch[N];
int main(){
	n=read(),m=read(),T=read();
	scanf("%s",ch+1);
	all=(1<<m)-1;
	for(int i=1;i<=n;++i){
		a[i]=ch[i]-'A';
		++s[a[i]][i];
		lim|=1<<a[i];
	}
	for(int i=0;i<m;++i){
		g[i]=read();
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<m;++j){
			b[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j)s[j][i]+=s[j][i-1];
	}
	for(int i=0;i<m;++i)las[i]=n+1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<m;++j){
			if(las[j]>n)continue;
			int st=0;
			for(int k=0;k<m;++k){
				if(s[k][las[j]-1]-s[k][i]>0)st|=1<<k;
			}
			if(st>>a[i]&1)continue;
			t[st]+=b[a[i]][j],t[st|(1<<a[i])|(1<<j)]+=b[a[i]][j];
			t[st|(1<<a[i])]-=b[a[i]][j],t[st|(1<<j)]-=b[a[i]][j];
		}
		las[a[i]]=i;
	}
	for(int j=0;j<m;++j){
		for(int i=0;i<=all;++i){
			if(i>>j&1)t[i]+=t[i^(1<<j)];
		}
	}
	for(int i=0;i<all;++i){
		if(i&(all^lim)||i==lim)continue;
		int tmp=0;
		for(int j=0;j<m;++j){
			if(i>>j&1)tmp+=g[j];
		}
		if(1LL*tmp+t[i]<=T)++ans;
	}
	printf("%d\n",ans);
	return 0;
}