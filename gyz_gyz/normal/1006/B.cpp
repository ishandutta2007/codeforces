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
#define N 100010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
struct pr{int x,y;}a[N];
bool cmp(pr x,pr y){
	if(x.x==y.x)return x.y<y.y;else return x.x>y.x;
}
int n,k,ans,b[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i].x);a[i].y=i;
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,k)b[i]=a[i].y,ans+=a[i].x;
	sort(b+1,b+k+1);b[k]=n;printf("%d\n",ans);
	rep(i,1,k)printf("%d ",b[i]-b[i-1]);
}