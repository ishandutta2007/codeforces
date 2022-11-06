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
#define N 200010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,m,a[5000];double ans;
int main(){
	scanf("%d%d",&n,&m);ans=m;
	rep(i,1,n)scanf("%d",&a[i*2-1]);
	scanf("%d",&a[n*2]);
	rep(i,1,n-1)scanf("%d",&a[i*2]);
	rep(i,1,n*2)if(a[i]==1){
		printf("-1\n");return 0;
	}
	dep(i,n*2,1)ans+=ans/(a[i]-1);
	printf("%.10lf",ans-m);
}