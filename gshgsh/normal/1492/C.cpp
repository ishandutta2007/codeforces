#include<iostream>
#include<string>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,M,f[MAXN],g[MAXN],ans;string a,b;
int main()
{
	cin>>N>>M>>a>>b;int j=0;For(i,0,M-1){while(a[j]!=b[i])j++;f[i]=j;j++;}j=N-1;FOR(i,M-1,0){while(a[j]!=b[i])j--;g[i]=j;j--;}
	For(i,1,M-1)ans=max(ans,g[i]-f[i-1]);cout<<ans<<endl;return 0;
}