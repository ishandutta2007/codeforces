#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1000001
int N,M,tot,prm[MAXN],phi[MAXN];ll ans=2;bool Not[MAXN];
int main()
{
	cin>>N>>M;if(M==1){cout<<3<<endl;return 0;}For(i,2,N){if(!Not[i])prm[++tot]=i,phi[i]=i-1;for(int j=1;j<=tot&&i*prm[j]<=N;j++){Not[i*prm[j]]=1;if(i%prm[j]==0){phi[i*prm[j]]=phi[i]*prm[j];break;}phi[i*prm[j]]=phi[i]*(prm[j]-1);}}
	sort(phi+3,phi+N+1);For(i,3,3+M-1)ans+=phi[i];cout<<ans<<endl;return 0;
}