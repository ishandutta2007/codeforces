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
#define N 300010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int T,n;char s[200];bool u;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);scanf("%s",s+1);u=1;
		rep(i,1,(n+1)/2)
			if(s[i]!=s[n-i+1]&&s[i]-s[n-i+1]!=2&&s[n-i+1]-s[i]!=2){
				printf("NO\n");u=0;break;
			}
		if(u)printf("YES\n");
	}
}