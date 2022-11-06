#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int mo=1e9+7;
int a[N];bool v[N];
int main(){int n,m;vector<pii>p,q;
	scanf("%d%d",&n,&m);
	rep(i,1,m){int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op)p.pb({l,r});else q.pb({l,r});
	}
	sort(p.begin(),p.end());int x=1;
	for(auto &i:p){
		if(x<i.fr)x=i.fr;
		while(x<i.sc)v[x++]=1;
	}int nw=0;
	dep(i,n,1)if(v[i])a[i]=a[i+1];else a[i]=++nw;
	for(auto &i:q)if(a[i.fr]<=a[i.sc])return printf("NO\n"),0;
	printf("YES\n");
	rep(i,1,n)printf("%d ",a[i]);
}