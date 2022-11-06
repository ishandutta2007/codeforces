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
int n,x,v[N];ll t,a[N],b[N],c[N];
int main(){
	scanf("%d%I64d",&n,&t);
	rep(i,1,n)scanf("%I64d",&a[i]);
	rep(i,1,n)c[i]=Inf*4,b[i]=a[i]+t;
	rep(i,1,n){
		scanf("%d",&x);v[i]++;v[x]--;
		if(x<i){printf("No");return 0;}
		if(x<n)c[x]=min(c[x],a[x+1]+t);
	}
	rep(i,1,n){v[i]+=v[i-1];
		if(v[i])b[i]=max(b[i],a[i+1]+t);
		b[i]=max(b[i],b[i-1]+1);
		if(c[i]<=b[i]){printf("No");return 0;}
	}
	printf("Yes\n");
	rep(i,1,n)printf("%I64d ",b[i]);
}