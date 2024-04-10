#include <bits/stdc++.h>
#define re register int 
#define il inline
#define ll long long
#define int unsigned long long 
using namespace std;
const int inf=1e9;
il int read(){
	char c=getchar();int z=0,f=1;
	while(c!='-'&&(c>'9'||c<'0')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') z=(z<<1)+(z<<3)+c-'0',c=getchar();
	return z*f;
}
int T,n,now;
const int N = 1e5+5;
//il int dfs(int who,int x){
//	if(f[who][x]) return f[who][x];
//	if(!x) return 0;
//	if(x&1) f[who][x]=x-dfs(who^1,x-1);
//	else{
//		if(((x>>1)&1)||(x==(x&-x))) f[who][x]=x-dfs(who^1,x>>1);
//		else f[who][x]=x-dfs(who^1,x-1);
//	}
//	return f[who][x];
//}
il int dfs(int x){
	if(!x) return 0;
	if(x==1) return 1;
	if((!((x>>1)&1))&&(x!=(x&-x))) return 1+dfs(x-2);
	return x/2+dfs(x/2-1);
}
il void work(){
	n=read();
	int ans=0,one=0;
//	cout<<now<<' ';
	if(n&1) cout<<n-dfs(n-1)<<'\n';
	else cout<<dfs(n)<<'\n';
}
signed main (){
	T=read();
	for(now=1;now<=T;now++) work();
	return 0;
}