#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <iostream>
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

long long pw[1005];
inline long long work(long long x){
	long long Ans=0;int c=0,fir=0;
	for(long long p=x;p;p/=10,c++) if(p<10) fir=p;
	if(x<10) return x;
	For(i,1,c-1){
		Ans+=9ll*pw[max(0,i-2)];
	}
	For(i,1,fir-1) Ans+=pw[c-2];
	if(x<100){
		return Ans+((x/10)<=(x%10));
	}
	long long v=(x/10)%pw[c-2];
	Ans+=v+1;
	if(x%10<fir) Ans--;
	return Ans;
}

long long l,r;
int main(){
	cin>>l>>r;
	*pw=1;For(i,1,18) pw[i]=1ll*pw[i-1]*10ll;
	long long Ans=work(r)-work(l-1);
	cout<<Ans<<endl;
	return 0;
}