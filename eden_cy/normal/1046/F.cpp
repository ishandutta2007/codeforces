#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}
inline void pt(int x) {
	if(!x) putchar('0');
	static int Stk[30],tp=0;
	for(; x; x/=10) Stk[tp++]=x%10;
	while(tp) putchar(Stk[--tp]^48);
}
inline void ptk(const int &x) {pt(x);putchar(' ');}
inline void ptn(const int &x) {pt(x);putchar('\n');}

inline bool chkmx(int &x,const int &y) {return x<y?x=y,true:false;}
inline bool chkmi(int &x,const int &y) {return x>y?x=y,true:false;}

const int M=(int)2e5+500;

int val[M];
int main() {
	int n;
	rd(n);
	FOR(i,1,n) rd(val[i]);
	int x,f;
	rd(x);rd(f);
	ll res=0;
	FOR(i,1,n) {
		int t=val[i];
		int l=1,r=t,tmp=1;
		while(l<=r) {
			int mid=l+r>>1;
			if((t-(mid-1)*f)<=1ll*mid*x) tmp=mid,r=mid-1;
			else l=mid+1;
		}
		res+=tmp-1;
	}
	cout<<res*f<<endl;
	return 0;
}