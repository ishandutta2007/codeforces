#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,mi,mx,a[N];map<int,int>s,t;
int main(){
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);++a[x];
	}int sz=n;
	rep(i,0,n)if(a[i])s[i]=a[i];
	rep(i,1,n){
		if(s.empty())break;t[0]=1;
		auto pt=--s.end();
		int x=pt->fr-i+1;--sz;
		if(!x)break; 
		if(!--pt->sc)s.erase(pt);
		if(sz<x){
			auto pt=--t.end();
			++s[pt->fr+i-1];++sz;
			if(!(--pt->sc))t.erase(pt);
		}
		while(sz>x){
			auto pt=s.begin();
			if(pt->sc>sz-x){
				pt->sc-=sz-x;t[pt->fr-i+1]+=sz-x;sz=x;
			}else{
				sz-=pt->sc;t[pt->fr-i+1]+=pt->sc;s.erase(pt);
			}
		}
		auto p1=s.begin();
		if((p1->fr-i)<0){
			if(p1->sc>i-mi){
				printf("-1\n");return 0;
			}
			mi+=p1->sc;sz-=p1->sc;s.erase(p1);
			if(!s.empty())p1=s.begin();else continue;
		}
		if(t.empty())continue;
		auto p2=--t.end();
		if(p1->fr-i<p2->fr){
			int x=min(p1->sc,p2->sc);
			s[p2->fr+i]+=x;t[p1->fr-i]+=x;
			if(!(p1->sc-=x))s.erase(p1);
			if(!(p2->sc-=x))t.erase(p2);
		}
	}
	sz=0;s.clear();t.clear();
	rep(i,1,n)if(a[i])s[i-1]=a[i],sz+=a[i];mx=sz;
	rep(i,1,n){
		if(s.empty())break;t[0]=1;
		auto pt=--s.end();
		int x=pt->fr-i+1;--sz;
		if(!x)break; 
		if(!--pt->sc)s.erase(pt);
		if(sz<x){
			auto pt=--t.end();
			++s[pt->fr+i-1];++sz;
			if(!(--pt->sc))t.erase(pt);
		}
		while(sz>x){
			auto pt=s.begin();
			if(pt->sc>sz-x){
				pt->sc-=sz-x;t[pt->fr-i+1]+=sz-x;sz=x;
			}else{
				sz-=pt->sc;t[pt->fr-i+1]+=pt->sc;s.erase(pt);
			}
		}
		auto p1=s.begin();
		if((p1->fr-i)<0){
			mx-=p1->sc;sz-=p1->sc;s.erase(p1);
			if(!s.empty())p1=s.begin();else continue;
		}
		if(t.empty())continue;
		auto p2=--t.end();
		if(p1->fr-i<p2->fr){
			int x=min(p1->sc,p2->sc);
			s[p2->fr+i]+=x;t[p1->fr-i]+=x;
			if(!(p1->sc-=x))s.erase(p1);
			if(!(p2->sc-=x))t.erase(p2);
		}
	}
	for(int i=mi;i<=mx;i+=2)printf("%d ",i);
}