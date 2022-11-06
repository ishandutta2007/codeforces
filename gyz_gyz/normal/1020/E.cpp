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
#define N 1000010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,x,ans,st[N],ed[N],nt[N],p[N];bool v[N],t[N];
void f(int x){v[x]=t[x]=1;
	for(int i=st[x];i;i=nt[i])v[p[i]]=1;
	rep(i,x+1,n)if(!v[i]){f(i);break;}
	if(t[x]){
		for(int i=st[x];i;i=nt[i])t[p[i]]=0;
		ans++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",&x,&p[i]);
		if(!st[x])st[x]=i;else nt[ed[x]]=i;ed[x]=i;
	}f(1);
	printf("%d\n",ans);
	rep(i,1,n)if(t[i])printf("%d ",i);
}