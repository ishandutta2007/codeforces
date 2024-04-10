#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
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
#define maxn 3005
#define inf 0x3f3f3f3f

int n,f[maxn][maxn],a[maxn];
void work()
{
	n=read();
	For(i,1,n)a[i]=i+read();
	For(i,2,n)
	{
		int now=0;
		For(j,i,n)f[i][j]=inf;
		Rep(j,i-1,1)
			if(a[j]>=i){
				f[i][a[j]]=min(f[i][a[j]],f[j][i-1]+now);
				now++;
			}
		For(j,i+1,n)f[i][j]=min(f[i][j],f[i][j-1]);
	}
	cout<<f[n][n]<<endl;
}

signed main()
{
	int T=read();
	while(T--)work(); 
	return 0;
}