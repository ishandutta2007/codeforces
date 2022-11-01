#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <set>
#define mp make_pair
#define pii pair<int,int>
#define For(i,a,n)  for(int i=(a);i<=(n);i++)
#define Forn(i,a,n) for(int i=(a);i>=(n);i--)
#define REP(i,n)    for(int i=(1);i<=(n);i++)
using namespace std;

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

int n,m,Ans[500005];
int tem[500005];
set<int> St;

int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) St.insert(i);
	For(i,1,m){
		*tem=0;
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		set<int>::iterator it=St.lower_bound(l);
		for(;it!=St.end() && (*it)<=r;it++){
			if(*it!=x){
				Ans[*it]=x;
				tem[++*tem]=*it;
			}
		}
		For(i,1,*tem) St.erase(tem[i]);
	}For(i,1,n) printf("%d ",Ans[i]);
	return 0;
}