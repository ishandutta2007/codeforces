#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 300010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,x,y;char s[N],t[N];bool u;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s);scanf("%s",t);
	if(n==m){u=1;
		rep(i,0,n-1)if(s[i]!=t[i]){u=0;break;}
		if(u){printf("YES");return 0;}
	}
	for(;(x<n)&&(s[x]==t[x]);)x++;
	for(y=1;(y<=n)&&(s[n-y]==t[m-y]);)y++;
	if((m-y>=x-1)&&(x==n-y)&&(s[x]=='*'))printf("YES");else printf("NO");
}