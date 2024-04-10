#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
const char S[4]="RGB";
int n,a[N][3],f[N][3];char s[N];
void prt(int i,int j){
	if(i>1)prt(i-1,f[i][j]);
	printf("%c",S[j]);
}
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	rep(i,0,2)a[1][i]=(s[1]!=S[i]);
	rep(i,1,n)rep(j,0,2){a[i][j]=n+1;
		rep(k,0,2)if(j!=k){
			int v=a[i-1][k]+(s[i]!=S[j]);
			if(v<a[i][j])a[i][j]=v,f[i][j]=k;
		}
	}
	int ans=n+1,x;
	rep(i,0,2)if(a[n][i]<ans)ans=a[n][i],x=i;
	printf("%d\n",ans);prt(n,x);
}