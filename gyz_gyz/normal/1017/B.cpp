#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n;ll a[4];char s[N],t[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);scanf("%s",t+1);
	rep(i,1,n)a[(s[i]-'0')+(t[i]-'0')*2]++;
	printf("%I64d\n",a[0]*a[1]+a[0]*a[3]+a[1]*a[2]);
}