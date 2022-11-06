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
#define N 3000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define n2 500000004
#define eps 1e-8
using namespace std;
int n;ll a[N],ans,s1,s2;
int main(){
	scanf("%d",&n);s1=-inf;s2=inf;
	rep(i,1,n){
		scanf("%I64d",&a[i]);ans+=abs(a[i]);
		if(a[i]>s1)s1=a[i];
		if(a[i]<s2)s2=a[i];
	}
	if(n==1)printf("%I64d",a[1]);
	else printf("%I64d",ans+min(s1,0ll)*2-max(s2,0ll)*2);
}