#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define N 200010
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
int n,m,Q,f[N],ans,vis[N];
vector<int> a[N];
int getf(int x){
	if(f[x]==x)return x;
	return f[x]=getf(f[x]);
}
inline void Merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx^fy){
		f[fy]=fx;
	}
}
int main(){
	n=read(),m=read(),Q=read();
	if(!Q){
		printf("%d\n",n+m-1);
		return 0;
	}
	while(Q--){
		int x=read(),y=read();
		a[x].push_back(y);
	}
	for(int i=1;i<=m;++i)f[i]=i;
	for(int i=1;i<=n;++i){
		int las=0;
		if(!a[i].size())++ans;
		for(auto x:a[i]){
			if(las)Merge(las,x);
			las=x;
		}
	}
	for(int i=1;i<=m;++i){
		if(getf(i)==i)++ans;
	}
	printf("%d\n",ans-1);
	return 0;
}