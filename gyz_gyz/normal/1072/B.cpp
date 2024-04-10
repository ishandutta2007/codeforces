#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 200000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,m,a[N],b[N],t[N];
void tr(){
	rep(i,1,n-1){
		if((a[i]&t[i])!=t[i]||(t[i]&b[i])!=b[i])return;
		t[i+1]=a[i]-t[i]+b[i];
	}
	printf("YES\n");
	rep(i,1,n)printf("%d ",t[i]);exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1)scanf("%d",&a[i]);
	rep(i,1,n-1)scanf("%d",&b[i]);
	rep(i,1,n-1)if((a[i]&b[i])!=b[i]){
		printf("NO\n");return 0;
	}
	for(;t[1]<4;t[1]++)tr();
	printf("NO\n");
}