#include<bits/stdc++.h>
using namespace std;
#define N 2333
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
int n,vis[N],m,rt;
int main(){
	n=read(),m=read();
	for(int i=1;i<=(m<<1);++i){
		vis[read()]=1;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){rt=i;break;}	
	}
	printf("%d\n",n-1);
	for(int i=1;i<=n;++i){
		if(i==rt)continue;
		printf("%d %d\n",i,rt);
	}
	return 0;
}