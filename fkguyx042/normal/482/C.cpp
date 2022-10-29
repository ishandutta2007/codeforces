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
const int maxn=(1<<20)+5;
const long long UPL=(1LL<<20)-1;

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

int n,m,upl;
char s[55][25];
long long F[maxn],cnt[25];
int clz[maxn];

int count(long long s){
	return clz[(s>>40)&UPL]+clz[(s>>20)&UPL]+clz[s&UPL];
}

int main(){
	scanf("%d\n",&n);
	For(i,1,n) gets(s[i]+1);m=strlen(s[1]+1);
	For(i,1,n)
	For(j,1,n){
		if(i==j)continue;
		int msk=0;
		For(k,1,m)
		if(s[i][k]==s[j][k]){
			msk|=1<<(k-1);
		}
		F[msk]|=1LL<<(i-1);
	}upl=(1<<m)-1;
	For(i,0,m-1)
	For(j,0,upl){
		if((j>>i)&1) F[j^(1<<i)]|=F[j];
	}
	For(i,0,UPL) clz[i]=clz[i>>1]+(i&1);
	For(i,0,upl){
		int A=clz[i]+1;
		For(j,0,m-1){
			if((i>>j)&1)continue;
			long long sum=F[i]^F[i^(1<<j)];
			cnt[A]+=count(sum);
		}
	}
	long double ans=0;
	For(i,1,m){
		long double gx=1.*cnt[i]*i;
		For(j,0,i-2) gx*=1.*(i-1-j)/(m-j);
		gx/=(m-i+1);
		ans+=gx;
	}
	printf("%.14lf\n",double(ans/n));
	return 0;
}