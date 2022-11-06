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
#define N 5000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
ll n,m,t1,t2,ans;
int main(){
	scanf("%I64d%I64d",&n,&m);ans=Inf;
	rep(i,1,n+m){
		if(1ll*i*i>n+m)break;
		if(!(n%i))t1=i;if(!(m%i))t2=i;
		if((!((n+m)%i))&&((((n/t1)<=(n+m)/i)||((m/t2)<=(n+m)/i))&&((n+m)/i+i<ans)))ans=(n+m)/i+i;
	}
	printf("%I64d\n",ans*2);
}