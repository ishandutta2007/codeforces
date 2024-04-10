#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e5+1,mod=1e9+9;
char st[N];
int n,a,b,k,ans,q,p;
V check(int&x){x-=mod,x+=x>>31&mod;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
I calc(int x,int n){return x<=1?x*n:Pow(x-1,mod-2,Pow(x,n)-1);}
V input(){scanf("%d%d%d%d%s",&n,&a,&b,&k,st);}
V init(){p=Pow(a,mod-2,b),q=calc(Pow(p,k),(n+1)/k);}
V work(){
	int v;
	FOR(i,0,k-1)v=Pow(p,i,q),st[i]=='+'?check(ans+=v):check(ans+=mod-v);
	cout<<Pow(a,n,ans);
}
int main(){
	input();
	init();
	work();
	return 0;
}