#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;char s[N];
int main(){
	scanf("%d%s",&n,s+1);bool fl=0;
	queue<int>a,b;
	rep(i,1,n)if(s[i]=='8')a.push(i);else b.push(i);
	for(;a.size()+b.size()>11;fl^=1){
		if(fl){
			if(a.empty())b.pop();else a.pop();
		}else{
			if(b.empty())a.pop();else b.pop();
		}
	}
	if(b.empty()||(!a.empty()&&a.front()<b.front()))
	printf("YES\n");else printf("NO\n");
}