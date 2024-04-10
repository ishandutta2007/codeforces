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
typedef long long LL;

//A back
//B not Back
LL flA[100005],flB[100005];
LL frA[100005],frB[100005];
int a[100005],n;

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

int main(){
	scanf("%d",&n);
	For(i,2,n) scanf("%d",&a[i]);
	For(i,2,n){
		if(a[i]==1) flA[i]=0;else flA[i]=flA[i-1]+(a[i]/2)*2;
		int A=(a[i]&1)?(a[i]):(a[i]-1);
		flB[i]=max(flA[i-1],flB[i-1])+A;
	}
	Forn(i,n-1,1){
		if(a[i+1]==1) frA[i]=0;else frA[i]=frA[i+1]+(a[i+1]/2)*2;
		int A=(a[i+1]&1)?(a[i+1]):(a[i+1]-1);
		frB[i]=max(frA[i+1],frB[i+1])+A;
	}LL Ans=0;
	For(i,1,n){
		Ans=max(Ans,flA[i]+frA[i]);
		Ans=max(Ans,frA[i]+flB[i]);
		Ans=max(Ans,flA[i]+frB[i]);
	}printf("%I64d\n",Ans);
	return 0;
}