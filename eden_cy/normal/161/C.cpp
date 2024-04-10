#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)

typedef long long ll;
typedef pair<ll,ll> pll;

const ll H=(ll)2e9;

map<pll,int> mark;

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}
int solve(int a,int b,int c,int d,int l,int r) {
	if(a>c) swap(a,c),swap(b,d);
	if(a==c&&b>d) swap(a,c),swap(b,d);
	
	if(mark[(pll){a*H+b,c*H+d}]) return mark[(pll){a*H+b,c*H+d}]-1;
	int mid=l+r>>1;
	int tmp=0;
	
	if(a>mid) a-=mid,b-=mid;
	if(c>mid) c-=mid,d-=mid;
	
	if(a==c&&b==d) tmp=b-a+1;
	else {
		tmp=max(tmp,min(b,d)-max(a,c)+1);
		
		if(b<mid&&d<mid) tmp=max(tmp,solve(a,b,c,d,l,mid-1));
		else if(b>=mid&&d>=mid) {
			tmp=max(tmp,solve(a,mid-1,1,d-mid,l,mid-1));
			tmp=max(tmp,solve(c,mid-1,1,b-mid,l,mid-1));
		} else if(b>=mid) {
			tmp=max(tmp,solve(a,mid-1,c,d,l,mid-1));
			tmp=max(tmp,solve(1,b-mid,c,d,l,mid-1));
		} else if(d>=mid) {
			tmp=max(tmp,solve(c,mid-1,a,b,l,mid-1));
			tmp=max(tmp,solve(1,d-mid,a,b,l,mid-1));
		}
	}
	mark[(pll){a*H+b,c*H+d}]=tmp+1;
	return tmp;
}
int main() {
	int a,b,c,d;
	rd(a);rd(b);rd(c);rd(d);
	int l=1,r=1073741823;
//	while(true) {
//		int mid=l+r>>1;
//		if(a>mid) a-=mid,b-=mid;
//		if(c>mid) c-=mid,d-=mid;
//		if(a<=mid&&mid<=b) break;
//		if(c<=mid&&mid<=d) break;
//	}
	printf("%d\n",solve(a,b,c,d,l,r));
	return 0;
}