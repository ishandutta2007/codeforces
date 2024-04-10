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
char A[200005],B[200005];
long double Ans,An;
long double SumA[26][200005],SumB[26][200005];

int main(){
	scanf("%d",&n);
	scanf("%s",A+1);
	scanf("%s",B+1);
	For(i,1,n) Ans+=1ll*i*i;
	For(i,1,n){
		For(j,0,25) SumA[j][i]=SumA[j][i-1];
		SumA[B[i]-'A'][i]+=i;
	}
	Forn(i,n,1){
		For(j,0,25) SumB[j][i]=SumB[j][i+1];
		SumB[B[i]-'A'][i]+=n-i+1;
	}
	For(i,1,n){
		An+=(n-i+1)*SumA[A[i]-'A'][i];
		An+=i*SumB[A[i]-'A'][i+1];
	}An/=Ans;
	printf("%.15lf\n",double(An));
	return 0;
}