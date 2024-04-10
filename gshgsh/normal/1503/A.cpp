#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN],b[MAXN];string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>s;s=" "+s;int cnt=0;For(i,1,N)cnt+=s[i]-'0';if(s[1]!='1'||s[N]!='1'||(cnt&1)){cout<<"NO\n";continue;}
		int tot=0,flag=1;For(i,1,N)s[i]=='1'?a[i]=b[i]=tot<cnt/2?1:-1,tot++:(a[i]=flag,b[i]=flag=-flag);
		cout<<"YES\n";For(i,1,N)cout<<(a[i]>0?'(':')');cout<<endl;For(i,1,N)cout<<(b[i]>0?'(':')');cout<<endl;
	}
	return 0;
}