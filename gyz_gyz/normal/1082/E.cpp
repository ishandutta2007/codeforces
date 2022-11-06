#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 600000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,ans,a[N],s[N],b[N],t[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		b[i]=b[i-1]+(a[i]==m);
		if(a[i]!=m){
			if(t[a[i]])s[i]=s[t[a[i]]]-b[i]+b[t[a[i]]-1]+1;
			s[i]=max(s[i],1);ans=max(ans,s[i]);
		}t[a[i]]=i;
	}
	printf("%d\n",ans+b[n]);
}