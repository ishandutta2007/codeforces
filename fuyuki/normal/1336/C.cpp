#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=3e3+5,mod=998244353;
char a[N],b[N];
int n,m,ans,f[N][N],g[N][N];
V check(int&x){x-=mod,x+=x>>31&mod;}
I equal(int x,int y){return y>m||a[x]==b[y];}
int main(){
	scanf("%s%s",a+1,b+1),n=strlen(a+1),m=strlen(b+1);
	FOR(i,1,n+1)f[i][i-1]=1;
	FOR(i,1,n){
		for(int l=1,r=i-1;r<=n;l++,r++){
			if(l>0&&equal(i,l-1))check(f[l-1][r]+=f[l][r]);
			if(r<n&&equal(i,r+1))check(f[l][r+1]+=f[l][r]);
		}
		if(i>=m)check(ans+=f[1][i]);
	}
	cout<<ans;
	return 0;
}