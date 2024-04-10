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
int n,m,op,a[N],l[N],r[N],t[N];bool v[N];
void sol(int s){
	if(s){
		v[s]=1;printf("%d\n",s);return;
	}
	rep(i,1,m)if(!v[l[i]]){
		v[l[i]]=1;printf("%d\n",l[i]);return;
	}int x=0;
	rep(i,1,n*2)if(!v[i]&&a[i]>a[x])x=i;
	v[x]=1;printf("%d\n",x);
}
int del(){int x;
	fflush(stdout);scanf("%d",&x);
	v[x]=1;if(!v[t[x]])return t[x];else return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n*2)scanf("%d",&a[i]);
	rep(i,1,m){
		scanf("%d%d",&l[i],&r[i]);
		if(a[l[i]]<a[r[i]])swap(l[i],r[i]);
		t[l[i]]=r[i];t[r[i]]=l[i];
	}
	scanf("%d",&op);
	rep(i,1,n)if(op==2)sol(del());
	else {sol(0);del();}
}