#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define pb push_back
#define MAXN 300001
int T,N,K,a[MAXN],val[MAXN];
int getc(){char c=getchar();while(c!='0'&&c!='1'&&c!='?')c=getchar();return c=='?'?2:c-'0';}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;For(i,1,N)a[i]=getc();For(i,0,K-1)val[i]=2;
		bool flag=1;For(i,1,N)if(val[i%K]==2)val[i%K]=a[i];else if(a[i]+val[i%K]==1){flag=0;break;}if(!flag){cout<<"NO\n";continue;}
		int cnt1=0,cnt2=0;For(i,0,K-1)cnt1+=val[i]==1,cnt2+=val[i]==2;cout<<(K/2>=cnt1&&K/2<=cnt1+cnt2?"YES\n":"NO\n");
	}
	return 0;
}