#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 400001
int N,f[MAXN],c[MAXN],mx[MAXN],ans;
int main()
{
	cin>>N;For(i,1,N){int a,b;cin>>a>>b;if(min(a,b)>N){cout<<-1<<endl;return 0;}if(a>b)swap(a,b),c[a]=1;f[a]=b;}FOR(i,N,1)mx[i]=max(mx[i+1],f[i]);vector<int>a,b;int c0=0,c1=0,mn=N*2+1;
	For(i,1,N)
	{
		if(a.empty()||a.back()>f[i])a.push_back(f[i]),c0+=c[i];else if(b.empty()||b.back()>f[i])b.push_back(f[i]),c1+=c[i];else {cout<<-1<<endl;return 0;}mn=min(mn,f[i]);
		if(mn>mx[i+1])ans+=min(c0+b.size()-c1,c1+a.size()-c0),c0=c1=0,a.clear(),b.clear();
	}
	cout<<ans<<endl;return 0;
}