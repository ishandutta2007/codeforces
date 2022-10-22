#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,x,tot,prm[MAXN];bool Not[MAXN];
int main()
{
	int N=MAXN-1;For(i,2,N){if(!Not[i])prm[++tot]=i;for(int j=1;j<=tot&&i*prm[j]<=N;j++){Not[i*prm[j]]=1;if(i%prm[j]==0)break;}}
	cin>>T;while(T--){cin>>x;int a=0;For(i,x+1,N)if(!Not[i]){a=i;break;}For(i,a+x,N)if(!Not[i]){cout<<1ll*a*i<<endl;break;}}return 0;
}