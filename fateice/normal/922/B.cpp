#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n,p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	  for(j=i;j<=n;j++)
	    {
		 k=i^j;
		 if(j<=k && k<=n && i+j>k)
		   p++;
		}
	cout<<p;
	return 0;
}