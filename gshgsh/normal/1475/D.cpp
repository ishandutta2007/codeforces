#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffff
#define MAXN 200001
int T,N,M,a[MAXN],b[MAXN],x[MAXN],y[MAXN];ll s1[MAXN],s2[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)cin>>a[i];For(i,1,N)cin>>b[i];int A=0,B=0;For(i,1,N)b[i]==1?x[++A]=a[i]:y[++B]=a[i];
		sort(x+1,x+A+1,greater<int>());sort(y+1,y+B+1,greater<int>());For(i,1,A)s1[i]=s1[i-1]+x[i];For(i,1,B)s2[i]=s2[i-1]+y[i];
		int r=B,ans=A+B*2+1;For(i,0,A){while(r&&s1[i]+s2[r-1]>=M)r--;if(s1[i]+s2[r]>=M)ans=min(ans,i+r*2);}cout<<(ans>A+B*2?-1:ans)<<endl;
	}
	return 0;
}