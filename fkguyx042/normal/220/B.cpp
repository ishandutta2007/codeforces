#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#define mp make_pair
#define pii pair<int,int>
#define For(i,a,n)  for(int i=(a);i<=(n);i++)
#define Forn(i,a,n) for(int i=(a);i>=(n);i--)
#define REP(i,n)    for(int i=(1);i<=(n);i++)
using namespace std;

int head[100005],a[100005],Hd[100005];
int nxt[100005],pre[100005],d[100005];
int Nxt[100005],Head[100005],Ans[100005],V[100005],Now[100005];
int tre[100005],n,Q,Tre[100005];

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

void Add(int *tre,int x,int delta){
	if(!x)return;
	for(int p=x;p<=n;p+=p&(-p)) tre[p]+=delta;
}

int ask(int *tre,int x){
	int ans=0;
	for(int p=x;p;p-=p&(-p)) ans+=tre[p];
	return ans;
}

int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]>n)continue;
		int v=a[i],t=head[v];
		if(t) nxt[t]=i;else Hd[v]=i;
		pre[i]=t;
		d[i]=d[t]+1;
		head[v]=i;
	}
	For(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		V[i]=l;
		Nxt[i]=Head[r];
		Head[r]=i;
	}
	For(i,1,n){
		if(i==3)
			i=3;
		if(d[i]>=a[i]){
			if(!Now[a[i]]) Now[a[i]]=Hd[a[i]];
			else Now[a[i]]=nxt[Now[a[i]]];
			Add(tre,n-pre[pre[Now[a[i]]]]+1,1);
			Add(tre,n-pre[Now[a[i]]]+1,-2);
			Add(tre,n-Now[a[i]]+1,1);
		}
		for(int j=Head[i];j;j=Nxt[j]){
			Ans[j]=ask(tre,n-V[j]+1);
		}
	}
	For(i,1,Q)printf("%d\n",Ans[i]);
	return 0;
}