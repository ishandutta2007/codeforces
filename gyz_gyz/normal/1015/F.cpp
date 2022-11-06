#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 300
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,x,u,f[N];ll a[N][N][N];char s[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	for(m=1;s[m+1];)m++;
	rep(i,2,m){
		for(x=f[i-1];x;x=f[x])if(s[x+1]==s[i])break;
		if(s[x+1]==s[i])f[i]=x+1;else f[i]=0;
	}
	a[0][0][0]=1;
	rep(i,1,n*2)rep(j,0,n){
		rep(k,0,m-1){
			if(s[k+1]=='(')u=1;else u=-1;
			if(j+u+1)add(a[i][j+u][k+1],a[i-1][j][k]);u=-u;
			for(x=f[k];x;x=f[x])if(s[x+1]!=s[k+1])break;
			if(s[x+1]!=s[k+1])x++;else x=0;
			if(j+u+1)add(a[i][j+u][x],a[i-1][j][k]);
		}
		add(a[i][j+1][m],a[i-1][j][m]);
		if(j)add(a[i][j-1][m],a[i-1][j][m]);
	}
	printf("%I64d\n",a[n*2][0][m]);
}