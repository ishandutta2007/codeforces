#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,t,a[N],b[N],c[N];ll ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		if(!b[a[i]])t++;b[a[i]]++;
	}
	rep(i,1,n){
		b[a[i]]--;if(!b[a[i]])t--;
		if(!c[a[i]])ans+=t;c[a[i]]++;
	}
	printf("%I64d\n",ans);
}