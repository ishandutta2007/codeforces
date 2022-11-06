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
#define n2 500000004
#define eps 1e-8
using namespace std;
int n,m;ll a[N],b[N],ans;
int main(){
	scanf("%d",&n);m=n;
	rep(i,1,n)scanf("%I64d",&a[i]);
	rep(i,1,m)scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	dep(i,n,1){
		if(a[n]>b[m])ans+=a[n--];else m--;
		if(a[n]>b[m])n--;else ans-=b[m--];
	}
	printf("%I64d",ans);
}