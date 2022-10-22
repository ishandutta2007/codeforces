#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n;
vector<int>a,b,c,d;
void sol()
{
	scanf("%d",&n);
	a.resize(n),b.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	int l=-1,r=n*2;
	while(r-l>1)
	{
		int mid=l+r>>1;
		c=a,d=b;
		for(int i=0;i<mid;i++)
			c.push_back(100),d.push_back(0);
		sort(c.begin(),c.end());
		sort(d.begin(),d.end());
		int s1=0,s2=0,k=n+mid;
		for(int i=k/4;i<k;i++)
			s1+=c[i],s2+=d[i];
		if(s1<s2)
			l=mid;
		else
			r=mid;
	}
	printf("%d\n",l+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}