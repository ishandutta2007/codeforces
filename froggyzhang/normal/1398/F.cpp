#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000100
inline int read(){
	int x=0,f=1;
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
int n,las[2],p[N],a[N],f[N];
char s[N];
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
int main(){
	n=read();
	scanf("%s",s+1);
	las[0]=las[1]=n+1;
	for(int i=n;i>=1;--i){
		if(s[i]^'?')las[s[i]-'0']=i;
		a[i]=max(las[0],las[1])-i;
		p[i]=i;
	}
	sort(p+1,p+n+1,[](const int i,const int j){return a[i]<a[j];});
	int pos=1;
	for(int i=1;i<=n+1;++i){
		f[i]=i;
	}
	for(int i=1;i<=n;++i){
		while(pos<=n&&a[p[pos]]<i){
			f[p[pos]]=f[p[pos]+1];
			++pos;
		}
		int u=1,ans=0;
		while(u<=n){
			u=getf(u);
			if(u>n)break;
			++ans,u+=i;
		}
		printf("%d ",ans);
	}
	return 0;
}