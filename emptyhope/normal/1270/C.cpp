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

int n;
void work()
{
	n=read();
	int xors=0,sum=0;
	For(i,1,n){
		int x=read();
		sum+=x,xors^=x;
	}
	if(xors*2==sum){
		puts("0");
		return;
	}
	puts("2");
	cout<<xors<<' ',sum+=xors;
	cout<<sum<<endl;
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}