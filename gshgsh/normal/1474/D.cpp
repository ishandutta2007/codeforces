#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN],b[MAXN],c[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],b[i]=c[i]=0;c[N+1]=0;For(i,1,N)b[i]=a[i]>=b[i-1]&&b[i-1]!=-1?a[i]-b[i-1]:-1;FOR(i,N,1)c[i]=a[i]>=c[i+1]&&c[i+1]!=-1?a[i]-c[i+1]:-1;
		if(!b[N]){cout<<"YES\n";continue;}bool flag=0;For(i,1,N-1)if(b[i-1]!=-1&&c[i+2]!=-1&&b[i-1]<=a[i+1]&&c[i+2]<=a[i]&&a[i+1]-b[i-1]==a[i]-c[i+2]){cout<<"YES\n";flag=1;break;}if(!flag)cout<<"NO\n";
	}
	return 0;
}