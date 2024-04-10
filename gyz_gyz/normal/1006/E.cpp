#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,m,tot,x,y,a[N],b[N],c[N],st[N],ed[N],nt[N];
void f(int x){a[++tot]=x;c[x]=tot;b[x]=1;
	for(int i=st[x];i;i=nt[i]){
		f(i);b[x]+=b[i];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,2,n){
		scanf("%d",&x);
		if(!st[x])st[x]=i;else nt[ed[x]]=i;ed[x]=i;
	}f(1);
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		if(y>b[x])printf("-1\n");
		else printf("%d\n",a[c[x]+y-1]);
	}
}