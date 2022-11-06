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
#define N 100000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,q,x,y,u,ans[N];char a[N],b[N];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",a+1);scanf("%s",b+1);
	rep(i,1,n-m+1){u=1;
		rep(j,1,m)if(a[i+j-1]!=b[j]){
			u=0;break;
		}
		ans[i]=ans[i-1]+u;
	}
	rep(i,1,q){
		scanf("%d%d",&x,&y);
		if(y-m+1>=x)printf("%d\n",ans[y-m+1]-ans[x-1]);
		else printf("0\n");
	}
}