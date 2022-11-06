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
#define N 1000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,x;ll ans,a[N];
int main(){
	scanf("%d",&n);ans=1;
	rep(i,1,n-1)ans=(ans<<1)%mo;
	ans=(mo+1-ans)%mo;
	rep(i,1,n)a[i]=1;
	rep(i,1,n){
		scanf("%d",&x);
		if(x!=-1){add(ans,a[x]);add(a[x],a[x]);}
	}
	printf("%I64d\n",(mo-ans)%mo);
}