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
int n,l[30],r[30];char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	rep(i,0,25)l[i]=n,r[i]=-1;
	rep(i,1,n){
		l[s[i]-'a']=min(l[s[i]-'a'],i);
		r[s[i]-'a']=max(r[s[i]-'a'],i);
	}
	rep(i,0,25)rep(j,i+1,25)if(r[i]>l[j])
		return printf("Yes\n%d %d\n",l[j],r[i]),0;
	printf("NO\n");
}