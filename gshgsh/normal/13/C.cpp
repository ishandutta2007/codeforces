#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define INF 0x3fffffffffffffff
#define MAXN 5001
int N,M,a[MAXN],b[MAXN];ll f[2][MAXN],ans;
int main()
{
    cin>>N;For(i,1,N)cin>>a[i],b[i]=a[i];sort(b+1,b+N+1);M=unique(b+1,b+N+1)-b-1;
    For(i,1,N){ll mn=INF;For(j,1,M)mn=min(mn,f[i-1&1][j]),f[i&1][j]=mn+abs(a[i]-b[j]);}
    ans=INF;For(i,1,M)ans=min(ans,f[N&1][i]);cout<<ans<<endl;return 0;
}