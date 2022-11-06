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
#define N 3010
#define M 10000010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,ans,tot,a[N],s[N],t[2][N*N];
int main(){
	scanf("%d",&n);tot=1;
	rep(i,1,n){
		scanf("%d",&s[i]);a[i+1]=1;int x=1;
		dep(j,i,1){a[j]=a[j+1];
			if(i-j)add(a[j],a[j+2]);
			if(i-j>1)add(a[j],a[j+3]);
			if(i-j>2&&!(!s[j]&&!s[j+1]&&s[j+2]&&s[j+3])
			&&!(!s[j]&&s[j+1]&&!s[j+2]&&s[j+3])
			&&!(s[j]&&s[j+1]&&s[j+2]&&!s[j+3])
			&&!(s[j]&&s[j+1]&&s[j+2]&&s[j+3]))add(a[j],a[j+4]);
			if(!t[s[j]][x]){
				t[s[j]][x]=++tot;add(ans,a[j]);
			}x=t[s[j]][x];
		}
		printf("%d\n",ans);
	}
}