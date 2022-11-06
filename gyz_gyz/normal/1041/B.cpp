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
ll x1,y1,x2,y2;
ll gcd(ll x,ll y){
	if(!x)return y;return gcd(y%x,x);
}
int main(){
	scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
	printf("%I64d",min(x1/(x2/gcd(x2,y2)),y1/(y2/(gcd(x2,y2)))));
}