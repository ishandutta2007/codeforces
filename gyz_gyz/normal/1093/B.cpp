#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m;char s[N];
void ck(){
	rep(i,1,m)if(s[i]!=s[m-i+1]){
		printf("%s\n",s+1);return;
	}printf("-1\n");
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",s+1);m=strlen(s+1);
		sort(s+1,s+m+1);ck();
	}
}