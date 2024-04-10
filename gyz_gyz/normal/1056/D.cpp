#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,f[N],s[N];
int main(){
	scanf("%d",&n);
	rep(i,2,n)scanf("%d",&f[i]);
	dep(i,n,1){
		if(!s[i])s[i]=1;s[f[i]]+=s[i];
	}
	sort(s+1,s+n+1);
	rep(i,1,n)printf("%d ",s[i]);
}