//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
vector<int>cand;
P2 e[3005];
int par[1005];
int ran[1005];
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		ran[i]=0;
	}
}
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x == y) return ;
	if(ran[x]<ran[y]){
		par[x]=par[y];
	}else{
		par[y]=par[x];
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}

int main()
{
	srand((unsigned int)time(NULL));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y,l,r; scanf("%d %d %d %d",&x,&y,&l,&r);
		e[i]=mp(mp(--x,--y),mp(l,r));
		cand.pb(l);
	}
	sort(cand.begin(),cand.end()); cand.erase(unique(cand.begin(),cand.end()),cand.end());
	int lb=0,ub=1000005;
	//[lb,ub)
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		for(int i=0;i<cand.size();i++)
		{
			int lb=cand[i];
			int ub=cand[i]+mid-1;
			init(n);
			for(int i=0;i<m;i++)
			{
				if(e[i].s.f<=lb && ub<=e[i].s.s)
				{
					unite(e[i].f.f,e[i].f.s);
				}
			}
			if(same(0,n-1)) goto ok;
		}
		ub=mid;
		continue;
		ok:;
		lb=mid;
	}
	if(lb) printf("%d\n",lb); else puts("Nice work, Dima!");
}