#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
const int sz=500;
int n,a[sz][sz], ord[sz];
typedef long long ll;
ll d[sz][sz], ans[sz];
bool added[sz];
int main()
{
	cin>>n;
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			scanf("%d",&a[i][j]);
			d[i][j] = a[i][j];
		}
	}
	rep(i,0,n)
		scanf("%d",&ord[i]);
	rep(i,0,n)
		added[i]=false;
	rep(t,0,n)
	{
		int k = ord[n-1-t]-1;
		added[k]=true;
		rep(i,0,n)
			for(int j=0;j<n;++j)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		rep(i,0,n)
			if(added[i])
				rep(j,0,n)
					if(added[j] && j!=i)
						ans[n-1-t]+=d[i][j];
	}
	rep(i,0,n)
		cout<<ans[i]<<" ";
	cout<<endl;
}