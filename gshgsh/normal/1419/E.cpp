#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define pb push_back
int T,N;bool prime(int x){for(int i=2;i*i<=x;i++)if(x%i==0)return 0;return 1;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;vector<int>d;for(int i=2;i*i<=N;i++)if(N%i==0)d.pb(i),i*i!=N?d.pb(N/i),0:0;sort(d.begin(),d.end());d.pb(N);
		if(d.size()==3&&prime(d[0])&&prime(d[1])){For(i,0,2)cout<<d[i]<<" \n"[i==2];cout<<"1\n";continue;}
		vector<int>prm;for(int i=2;i*i<=N;i++)if(N%i==0){prm.pb(i);while(N%i==0)N/=i;}if(N>1)prm.pb(N);
		if(prm.size()==1){for(auto i:d)cout<<i<<' ';cout<<"\n0\n";continue;}
		int M=prm.size(),K=d.size();vector<bool>vis(K);vector<int>nxt(K+M,-1);For(i,0,M-1){int p=prm[i],q=prm[(i+1)%M];For(j,0,K-1)if(!vis[j]&&d[j]%p==0&&d[j]%q==0){nxt[K+i]=j;vis[j]=1;break;}}
		For(i,0,M-1)For(j,0,K-1)if(!vis[j]&&d[j]!=prm[i]&&d[j]%prm[i]==0)nxt[j]=nxt[K+i],nxt[K+i]=j,vis[j]=1;
		For(i,0,M-1){int x=K+i;while(x!=-1)cout<<(x>=K?prm[x-K]:d[x])<<' ',x=nxt[x];}cout<<"\n0\n";
	}
	return 0;
}