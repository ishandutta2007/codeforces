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
int n;ll s,ans,a[N];
int main(){
	scanf("%d%I64d",&n,&s);
	rep(i,1,n)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n/2+1)if(a[i]>s)ans+=a[i]-s;
	rep(i,n/2+1,n)if(a[i]<s)ans+=s-a[i];
	printf("%I64d",ans);
}