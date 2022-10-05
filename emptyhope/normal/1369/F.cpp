#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define N 200005
bool win[N],lose[N];
int n,fwin,flose;

bool getwin(int s,int t)
{
	if(t&1){
		if(s&1) return 0;
		return 1;
	}
	if(s>t/2){
		if(s&1) return 1;
		return 0;
	}
	if(s>t/4) return 1;
	return getwin(s,t/4);
}
bool getlose(int s,int t){
	if(2*s>t)return 1;
	return getwin(s,t/2);
}

signed main()
{
	n=read();
	For(i,1,n){
		int s=read(),t=read();
		win[i]=getwin(s,t),lose[i]=getlose(s,t); 
	}
	fwin=0,flose=1;
	For(i,1,n){
		if(fwin==flose) break;
		if(fwin) win[i]^=1,lose[i]^=1;
		fwin=win[i],flose=lose[i];
	}
	cout<<fwin<<" "<<flose;
	return 0;
}