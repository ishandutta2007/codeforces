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
#define eps 1e-8
using namespace std;
int n,ans;char a[N],b[N];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);scanf("%s",b+1);
	rep(i,2,n)
		if((a[i]!=b[i])&&(a[i-1]!=b[i-1])&&(a[i]!=a[i-1])){
			swap(a[i],a[i-1]);ans++;
		}
	rep(i,1,n)if(a[i]!=b[i])ans++;
	printf("%d",ans);
}