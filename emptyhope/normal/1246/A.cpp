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

void work()
{
	
}
inline int cnt(int x){
	if(x<0)return 2333;
	int res=0;
	while(x)x^=x&-x,res++;
	return res;
}
signed main()
{
	int n=read(),p=read();
	For(i,0,32){
		if(i>=cnt(n-p*i) && i<=(n-p*i)){
			cout<<i<<endl;
			return 0;
		}
	}cout<<-1;
    return 0;
}