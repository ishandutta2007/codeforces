#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,k,tot,X[N],Y[N],ans[N],a[N];
set<int>p[N];bool v[N];
void dl(int x){tot--;v[x]=1;
	for(auto i:p[x])if(!v[i]){
		a[i]--;p[i].erase(p[i].lower_bound(x));
		if(a[i]<k)dl(i);
	}p[x].clear();
}
int main(){
	scanf("%d%d%d",&n,&m,&k);tot=n;
	rep(i,1,m){
		scanf("%d%d",&X[i],&Y[i]);
		p[X[i]].insert(Y[i]);p[Y[i]].insert(X[i]);
		a[X[i]]++;a[Y[i]]++;
	}
	rep(i,1,n)if((!v[i])&&(a[i]<k))dl(i);
	dep(i,m,1){
		ans[i]=tot;
		if((!v[X[i]])&&(!v[Y[i]])){
			a[X[i]]--;p[X[i]].erase(p[X[i]].lower_bound(Y[i]));
			a[Y[i]]--;p[Y[i]].erase(p[Y[i]].lower_bound(X[i]));
			if((!v[X[i]])&&(a[X[i]]<k))dl(X[i]);
			if((!v[Y[i]])&&(a[Y[i]]<k))dl(Y[i]);
		}
	}
	rep(i,1,m)printf("%d\n",ans[i]);
}