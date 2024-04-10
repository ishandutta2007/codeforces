#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
ll N[3],a[3][MAXN],sum[3];
int main()
{
	For(i,0,2)cin>>N[i];For(i,0,2){For(j,1,N[i])cin>>a[i][j],sum[i]+=a[i][j];sort(a[i]+1,a[i]+N[i]+1);}sort(sum,sum+3);
	cout<<sum[0]+sum[1]+sum[2]-2*min(sum[0],a[0][1]+a[1][1]+a[2][1]-max(a[0][1],max(a[1][1],a[2][1])))<<endl;
}