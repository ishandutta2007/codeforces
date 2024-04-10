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
int n,s,x;
int main(){
	scanf("%d",&n);while(s*s<n)s++;
	for(;x<n;x+=s){
		dep(i,min(x+s,n),x+1)printf("%d ",i);
	}
}