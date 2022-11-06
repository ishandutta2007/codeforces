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
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,x,y,ans,a[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		m-=y;a[i]=x-y;
		if(m<0)break;
	}
	if(m<0){printf("-1");return 0;}
	sort(a+1,a+n+1);ans=n;
	rep(i,1,n)if(a[i]<=m)m-=a[i],ans--;else break;
	printf("%d\n",ans);
}