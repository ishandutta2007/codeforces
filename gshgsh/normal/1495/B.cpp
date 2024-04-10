#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,a[MAXN],f[MAXN],g[MAXN],mx,cnt;
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];f[1]=1;For(i,2,N)mx=max(mx,f[i]=(a[i]>a[i-1])*f[i-1]+1);g[N]=1;FOR(i,N-1,1)mx=max(mx,g[i]=(a[i]>a[i+1])*g[i+1]+1);For(i,1,N)cnt+=(f[i]==mx)+(g[i]==mx);
	if(cnt!=2||!(mx&1)){cout<<0<<endl;return 0;}For(i,1,N)if(f[i]==mx||g[i]==mx){cout<<(f[i]==mx&&g[i]==mx)<<endl;return 0;}return 0;
}