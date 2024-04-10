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
struct pr{int x,y;}a[N];
int n,x;
bool cmp(pr x,pr y){
	if(x.y==y.y)return x.x<y.x;else return x.y>y.y;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){a[i].x=i;
		rep(j,1,4){
			scanf("%d",&x);
			a[i].y+=x;
		}
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)if(a[i].x==1){
		printf("%d\n",i);return 0;
	}
}