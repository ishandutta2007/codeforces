#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 233
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
int T,n,a[N],p[N];
bool l[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		int m=0;
		for(int i=1;i<=n;++i){
			l[i]=read();
			if(!l[i]){
				p[++m]=i;
			}
		}
		sort(p+1,p+m+1,[&](int i,int j){return a[i]>a[j];});
		int pos=0;
		for(int i=1;i<=n;++i){
			printf("%d ",l[i]?a[i]:a[p[++pos]]);
		}
		printf("\n");
	}
	return 0;
}