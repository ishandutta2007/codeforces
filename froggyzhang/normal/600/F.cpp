#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define M 100010
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
int A,B,m,x[M],y[M],ans;
int mp[N][N],d[N];
int main(){
	A=read(),B=read(),m=read();
	for(int i=1;i<=m;++i){
		x[i]=read(),y[i]=read()+A;
		++d[x[i]],++d[y[i]];
	}
	for(int i=1;i<=A+B;++i){
		ans=max(ans,d[i]);
	}
	for(int i=1;i<=m;++i){
		int p1=1,p2=1;
		while(mp[x[i]][p1])++p1;
		while(mp[y[i]][p2])++p2;
		mp[x[i]][p1]=y[i];
		mp[y[i]][p2]=x[i];
		if(p1==p2)continue;
		int u=y[i],zyk=p2;
		while(u){
			swap(mp[u][p1],mp[u][p2]);
			u=mp[u][zyk];
			zyk^=p1^p2;
		}
	}
	printf("%d\n",ans); 
	for(int i=1;i<=m;++i){
		for(int j=1;;++j){
			if(mp[x[i]][j]==y[i]){
				printf("%d ",j);
				break;
			}
		}
	}
	return 0;
}