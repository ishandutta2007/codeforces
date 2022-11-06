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
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,x,y,l,r,lp,rp,ls,rs;
int main(){
	scanf("%d",&n);r=rp=inf+1;
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		if(x>l)lp=l,l=x,ls=i;
		else if(x>lp)lp=x;
		if(y<r)rp=r,r=y,rs=i;
		else if(y<rp)rp=y;
	}
	if(ls==rs)printf("%d",max(rp-lp,0));
	else printf("%d",max(max(r-lp,rp-l),0));
}