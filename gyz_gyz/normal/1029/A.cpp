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
int n,k;char a[N];bool u;
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	rep(i,2,n+1){u=1;
		rep(j,i,n)if(a[j]!=a[j-i+1]){u=0;break;}
		if(u){
			rep(kk,1,k)rep(j,1,i-1)printf("%c",a[j]);
			rep(j,i,n)printf("%c",a[j]);return 0;
		}
	}
}