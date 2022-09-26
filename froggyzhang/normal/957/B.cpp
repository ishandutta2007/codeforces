#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 123
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
int n,m;
char a[N][N];
struct Union_Set{
	int f[N];
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
	}
}S;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
	}
	S.init(n+m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]=='#'){
				S.Merge(i,j+n);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(S.getf(i)==S.getf(j+n)&&a[i][j]!='#'){
				return !printf("No\n");
			}
		}
	}
	printf("Yes\n");
	return 0;
}