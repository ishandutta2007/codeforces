#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,x;ll a[N],b[N];bool u;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%I64d",&b[i]);b[0]=b[n];
	rep(i,1,n)if(b[i]>0){u=1;break;}
	if(!u){
		printf("YES\n");
		rep(i,1,n)printf("1 ");return 0;
	}
	rep(i,1,n)if((b[i]>b[i-1])&&((b[i]>b[x])||(!x)))x=i;
	if(!x){printf("NO");return 0;}a[x]=b[x];
	dep(i,x-1,1){
		a[i]=a[i%n+1]+b[i];
		if(a[i]%a[i%n+1]!=b[i])a[i]+=a[i%n+1],a[i%n+1]*=2;
	}
	dep(i,n,x+1){
		a[i]=a[i%n+1]+b[i];
		if(a[i]%a[i%n+1]!=b[i])a[i]+=a[i%n+1],a[i%n+1]*=2;
	}
	if(a[x]%a[x%n+1]!=b[x])a[x%n+1]+=a[x];
	printf("YES\n");
	rep(i,1,n)printf("%I64d ",a[i]);
}