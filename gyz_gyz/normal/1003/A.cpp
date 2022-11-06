#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,x,ans,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&x);a[x]++;}
	rep(i,1,100)if(a[i]>ans)ans=a[i];
	printf("%d\n",ans);
}