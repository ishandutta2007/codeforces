#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,a[11],b[11],ans;
int check(){int ca=0,cb=0;For(i,1,10){if(i&1)ca+=b[i];else cb+=b[i];if(ca+(10-i>>1)<cb)return i;if(cb+(11-i>>1)<ca)return i;}return 10;}
void dfs(int x){if(x==11){ans=min(ans,check());return;}if(a[x]!=2)b[x]=a[x],dfs(x+1);else b[x]=0,dfs(x+1),b[x]=1,dfs(x+1);}
int main()
{
	cin>>T;
	while(T--)
	{
		For(i,1,10){char c;cin>>c;a[i]=c!='?'?c-'0':2;}
		ans=10;dfs(1);cout<<ans<<endl;
	}
}