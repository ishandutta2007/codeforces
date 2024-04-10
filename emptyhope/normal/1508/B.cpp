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
#define maxn 200005
#define inf 0x3f3f3f3f

int n,k;
int a[maxn];
inline int cnt(int x){
	return (1ll<<(x-1));
}
void dfs(int n,int k,int now){
	if(now<=n-63) return dfs(n,k,now+1);
	if(now>=n) return;
//	cout<<"dfs "<<n<<' '<<k<<" "<<now<<endl;
	int lst=now;
	while(now<n && k>cnt(n-now))
		k-=cnt(n-now),now++;
//	cout<<n<<' '<<k<<" "<<now<<endl;
	reverse(a+lst,a+now+1);
	dfs(n,k,now+1);
}
void work()
{
	n=read(),k=read();
	if(n<=63 && k>(1ll<<(n-1))){
		puts("-1");
		return;
	}
	For(i,1,n)a[i]=i;
	dfs(n,k,1);
	For(i,1,n)cout<<a[i]<<" ";puts("");
}
// cnt[i] = (2^(i-1))
signed main()
{
//	cout<<(1ll<<62)<<endl;
//	cout<<1000000000000000000ll<<endl;
	int T=read();
	while(T--)work();
	return 0;
}