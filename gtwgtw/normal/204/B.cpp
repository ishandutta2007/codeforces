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

map<int,int> Mps;

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

int n,a[100005],b[100005];

int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		Mps[a[i]]++;
		if(a[i]!=b[i])Mps[b[i]]++;
	}int Ans=2100000000;
	for(map<int,int>::iterator it=Mps.begin();it!=Mps.end();it++){
		int p=it->second;
		if(p>=(n+1)/2){
			int A=0;
			For(i,1,n) if(a[i]==it->first) A++;
			int Step=max(0,(n+1)/2-A);
			Ans=min(Ans,Step);
		}
	}if(Ans==2100000000) printf("%d\n",-1);else printf("%d\n",Ans);
	return 0;
}