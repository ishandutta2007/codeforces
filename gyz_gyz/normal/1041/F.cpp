#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
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
#define N 262144
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,ans,x,a[N],b[N];
map<int,int>p;
int main(){
	scanf("%d%d",&n,&x);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d%d",&m,&x);ans=x=1;
	rep(i,1,m)scanf("%d",&b[i]);
	rep(i,1,n){
		while((x<n)&&(b[x]<a[i]))x++;
		if(b[x]==a[i])ans=2;
	}
	rep(i,1,31){p.clear();
		rep(j,1,n)ans=max(ans,++p[a[j]&((1<<i)-1)]);
		rep(j,1,m)ans=max(ans,++p[(b[j]&((1<<i)-1))^(1<<(i-1))]);
	}
	printf("%d",ans);
}