#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffffffffffff
#define MAXN 101
#define MAXM 20
int N,M,b,S;ll ans,f[2][1<<MAXM];struct A{int x,k,s;bool operator<(A a)const{return k<a.k;}}a[MAXN];
int main()
{
	cin>>N>>M>>b;For(i,1,N){cin>>a[i].x>>a[i].k;int x;cin>>x;while(x--){int y;cin>>y;a[i].s|=1<<y-1;}S|=a[i].s;}if(S!=(1<<M)-1){cout<<-1<<endl;return 0;}sort(a+1,a+N+1);
	ans=INF;memset(f,0x3f,sizeof(f));f[0][0]=0;For(i,0,N-1){For(j,0,(1<<M)-1)f[i+1&1][j]=f[i&1][j];For(j,0,(1<<M)-1)f[i+1&1][j|a[i+1].s]=min(f[i+1&1][j|a[i+1].s],f[i&1][j]+a[i+1].x);ans=min(ans,1ll*a[i+1].k*b+f[i+1&1][(1<<M)-1]);}
	cout<<ans<<endl;return 0;
}