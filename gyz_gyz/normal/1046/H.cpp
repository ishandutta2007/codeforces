#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,x;bool v[N];char ch[N];ll ans;
map<int,int>p;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",ch);
		rep(j,0,25)v[j]=0;x=0;
		for(int l=0;ch[l];l++)v[ch[l]-'a']^=1;
		dep(j,25,0)x=x*2+v[j];
		if(p.count(x))ans+=p[x];
		rep(j,0,25)if(p.count(x^(1<<j)))ans+=p[x^(1<<j)];
		p[x]++;
	}
	printf("%I64d",ans);
}