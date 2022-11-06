#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,t,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	printf("%d\n",n+1);
	dep(i,n,1){
		int dt=(i-1+n-(a[i]+t)%n)%n;
		printf("1 %d %d\n",i,dt);
		t=(t+dt)%n;
	}
	printf("2 %d %d\n",n,n);
}