#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
const int N=1010;
char t[N][N],s[N*N];bool v[N];
int main(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s);
	sort(s,s+n*m);int x=0;
	rep(j,0,m-1){
		rep(i,1,k)if(!v[i])t[i][j]=s[x++];
		rep(i,1,k)if(!v[i]&&t[i][j]!=t[k][j])v[i]=1;
	}
	rep(i,1,n)rep(j,0,m-1)if(!t[i][j])t[i][j]=s[x++];
	rep(i,1,n)printf("%s\n",t[i]);
}