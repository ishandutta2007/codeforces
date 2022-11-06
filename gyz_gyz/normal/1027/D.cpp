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
#define N 500000
#define K 15000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,ans,a[N],c[N],v[N],p[N];
void f(int x){v[x]=-2;
	if(a[x]==x){v[x]=x;return;}
	if(v[a[x]]==0){f(a[x]);
		if(v[a[x]]==a[x])v[x]=-1;else v[x]=v[a[x]];
	}else{
		if(v[a[x]]==-2)v[x]=a[x];else v[x]=-1;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)if(v[i]==0)f(i);
	rep(i,1,n)if(v[i]>0)p[v[i]]=inf;
	rep(i,1,n)if((v[i]>0)&&(c[i]<p[v[i]]))p[v[i]]=c[i];
	rep(i,1,n)if(v[i]>0)ans+=p[v[i]],p[v[i]]=0;
	printf("%d\n",ans);
}