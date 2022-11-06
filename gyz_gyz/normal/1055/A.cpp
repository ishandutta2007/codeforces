#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,m,a[N],b[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	if(!a[1]){printf("NO\n");return 0;}
	if(a[m]){printf("YES\n");return 0;}
	if(!b[m]){printf("NO\n");return 0;}
	rep(i,m+1,n)if(a[i]&&b[i]){
		printf("YES\n");return 0;
	}
	printf("NO\n");
}