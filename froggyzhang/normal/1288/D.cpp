#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
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
int vis[1<<8],tot;
int n,m,a[N][9],ansx,ansy;
bool check(int k){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		int st=0;
		for(int j=1;j<=m;++j){
			if(a[i][j]>=k){
				st|=1<<j-1;
			}
		}
		vis[st]=i;
	}
	for(int i=0;i<=tot;++i){
		for(int j=0;j<=tot;++j){
			if((i|j)==tot&&vis[i]&&vis[j]){
				ansx=vis[i],ansy=vis[j];
				return true;
			}
		}
	}
	return false;
}
int main(){
	n=read(),m=read();
	tot=(1<<m)-1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	ansx=ansy=1;
	int l=0,r=1e9+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	printf("%d %d\n",ansx,ansy);
	return 0;
}