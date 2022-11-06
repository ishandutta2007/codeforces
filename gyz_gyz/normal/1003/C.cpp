#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,k,a[N];double ans;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);a[i]+=a[i-1];
	}
	rep(i,0,n-k)rep(j,i+k,n)
		if(1.*(a[j]-a[i])/(j-i)>ans)
			ans=1.*(a[j]-a[i])/(j-i);
	printf("%.8lf",ans);	
}