#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 5010
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,k,a[N],c[N];bitset<N>v[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		int x=(i-1)%k+1;c[i]=x;
		if(v[a[i]][x])while(v[a[i]][c[i]]){c[i]=c[i]%k+1;
			if(c[i]==x)return printf("NO\n"),0;
		}
		v[a[i]][c[i]]=1;
	}printf("YES\n");
	rep(i,1,n)printf("%d ",c[i]);
}