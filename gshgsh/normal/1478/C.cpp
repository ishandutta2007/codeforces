#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N;ll a[MAXN],d[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N*2)cin>>d[i];sort(d+1,d+N*2+1,greater<ll>());bool flag=1;For(i,1,N*2)if(d[i]&1||((i&1)&&d[i]!=d[i+1])){cout<<"NO\n";flag=0;break;}
		if(flag){if(d[1]%(N*2)){cout<<"NO\n";flag=0;continue;}a[1]=d[1]/N/2;ll sum=a[1]*2;For(i,2,N){ll x=d[i*2],lst=(N-i+1)*2;if(x-sum<=0||(x-sum)%lst){cout<<"NO\n";flag=0;break;}a[i]=(x-sum)/lst;sum+=a[i]*2;if(a[i]==a[i-1]){cout<<"NO\n";flag=0;break;}}if(flag)cout<<"YES\n";}
	}
	return 0;
}