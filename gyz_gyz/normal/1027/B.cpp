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
#define N 100
#define K 15000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int q;ll n,x,y;
int main(){
	scanf("%I64d%d",&n,&q);
	rep(i,1,q){
		scanf("%I64d%I64d",&x,&y);
		printf("%I64d\n",(((x-1)*n+y+1)/2)+((x+y)&1)*(n*n+1)/2);
	}
}