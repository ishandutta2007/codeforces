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

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

int n;
int main(){
	scanf("%d",&n);
	if(n==3){
		puts("5");
		return 0;
	}
	if(n==1){
		puts("1");
		return 0;
	}int Ans;
	for(Ans=1;(Ans*Ans+1)>>1<n;Ans+=2);
	printf("%d\n",Ans);
	return 0;
}