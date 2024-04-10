#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 100001
int N,a[MAXN],b[MAXN];
int main()
{
	cin>>N;int cnt=0;For(i,1,N){char c;cin>>c;a[i]=c=='?'?10:c-'0';cnt+=a[i]==10;}For(i,1,N){char c;cin>>c;b[i]=c=='?'?10:c-'0';cnt+=b[i]==10;}
	int ans=1;For(i,1,cnt)ans=ans*10ll%P;bool flag=1;For(i,1,N)if(a[i]<10&&b[i]<10&&a[i]!=b[i]){flag=0;break;}if(flag){int mul=1;For(i,1,N)if(a[i]==10&&b[i]==10)mul=mul*10ll%P;ans=(ans+mul+P)%P;}
	bool flag1=0,flag2=0;For(i,1,N)if(a[i]<10&&b[i]<10)flag1|=a[i]<b[i],flag2|=a[i]>b[i];if(flag1&&flag2){cout<<ans<<endl;return 0;}
	if(!flag1){int mul=1;For(i,1,N)if(a[i]==10||b[i]==10)if(a[i]==b[i])mul=mul*55ll%P;else if(a[i]<10)mul=mul*(a[i]+1ll)%P;else mul=mul*(10ll-b[i])%P;ans=(ans-mul+P)%P;}
	if(!flag2){int mul=1;For(i,1,N)if(a[i]==10||b[i]==10)if(a[i]==b[i])mul=mul*55ll%P;else if(a[i]<10)mul=mul*(10ll-a[i])%P;else mul=mul*(b[i]+1ll)%P;ans=(ans-mul+P)%P;}cout<<ans<<endl;return 0;
}