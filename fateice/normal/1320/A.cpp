#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[200010];
L p;
map<int,L> f;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
       scanf("%d",&x[i]);
       f[i-x[i]]+=x[i];
       p=max(p,f[i-x[i]]);
      }
    cout<<p;
	return 0;
}