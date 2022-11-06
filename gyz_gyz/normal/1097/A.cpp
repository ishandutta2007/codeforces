#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
char s[9],t[9][9];
int main(){
	scanf("%s",s);
	rep(i,1,5)scanf("%s",t[i]);
	rep(i,1,5)if(s[0]==t[i][0]||s[1]==t[i][1]){
		printf("YES\n");return 0;
	}printf("NO\n");
}