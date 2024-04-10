#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN],ans[MAXN],tot,l[MAXN],r[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],ans[i]=0;tot=0;
		For(i,1,N)if(a[i]){while(tot&&l[tot]>=max(i-a[i]+1,1))tot--;if(tot&&r[tot]>=max(i-a[i],0))r[tot]=i;else l[++tot]=max(i-a[i]+1,1),r[tot]=i;}
		For(i,1,tot)For(j,l[i],r[i])ans[j]=1;For(i,1,N)cout<<ans[i]<<' ';cout<<endl;
	}
	return 0;
}