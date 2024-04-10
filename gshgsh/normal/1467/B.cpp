#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int T,N,a[MAXN];bool vis[MAXN];
bool check(int x){return x>1&&x<N&&((a[x]>a[x-1]&&a[x]>a[x+1])||(a[x]<a[x-1]&&a[x]<a[x+1]));}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],vis[i]=0;int cnt=0,ans=0;For(i,2,N-1)cnt+=vis[i]=check(i);ans=cnt;
		For(i,2,N-1){int tmp=a[i];a[i]=a[i-1];ans=min(ans,cnt-vis[i-1]-vis[i]-vis[i+1]+check(i-1)+check(i)+check(i+1));a[i]=a[i+1];ans=min(ans,cnt-vis[i-1]-vis[i]-vis[i+1]+check(i-1)+check(i)+check(i+1));a[i]=tmp;}cout<<ans<<endl;
	}
	return 0;
}