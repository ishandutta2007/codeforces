#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
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

long long n,m,Ans;
char A[1000005],B[1000005];
int lenA,lenB;
int f[1000005][27];

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

int main(){
	cin>>n>>m;
	scanf("%s",A+1);lenA=strlen(A+1);
	scanf("%s",B+1);lenB=strlen(B+1);
	int g=__gcd(lenA,lenB);
	int j=1;
	For(i,1,lenA){
		f[i%g][A[i]-'a']++;
	}
	int k=1;
	For(i,1,lenB){
		For(j,0,25) if(B[i]-'a'!=j){
			Ans+=f[i%g][j];
		}
	}lenB/=g;
	long long Lcm=1ll*lenA*lenB;
	cout<<Ans*(n*lenA/Lcm)<<endl;
	return 0;
}