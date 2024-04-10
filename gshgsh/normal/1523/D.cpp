#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<ctime>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
#define MAXM 15
int N,M,K,tot[1<<MAXM],tot2[1<<MAXM];ll a[MAXN],siz,ans;
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}int getsize(ll x){int ans=0;while(x)ans++,x-=x&-x;return ans;}
int main()
{
	srand(time(0));cin>>N>>M>>K;For(i,1,N)For(j,0,M-1)a[i]|=getc()+0ll<<j;
	For(i,1,100)
	{
		int id=((rand()<<15)|rand())%N+1,cnt=getsize(a[id]);vector<int>pos;For(j,0,M-1)if((a[id]>>j)&1)pos.push_back(j);For(j,0,(1<<cnt)-1)tot[j]=tot2[j]=0;
		For(j,1,N){int x=0;For(k,0,cnt-1)x|=((a[j]>>pos[k])&1)<<k;tot[x]++;}For(j,0,(1<<cnt)-1)for(int k=j;k;k=j&k-1)tot2[k]+=tot[j];
		For(j,0,(1<<cnt)-1)if(tot2[j]>=(N+1>>1)&&getsize(j)>siz){siz=getsize(j);ans=0;For(i,0,cnt-1)ans|=((j>>i)&1ll)<<pos[i];}
	}
	For(i,0,M-1)cout<<((ans>>i)&1);return 0;
}