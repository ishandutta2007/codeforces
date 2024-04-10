#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e6, K=3;
int n, a[sz];
long long bit[K][sz];

void add(int i, int k,long long x)
{
	while(i<sz)
	{
		bit[k][i]+=x;
		i+=i&(-i);
	}
}
long long query(int i,int k)
{
	long long x=0;
	while(i>0)
	{
		x+=bit[k][i];
		i-=i&(-i);
	}
	return x;
}
pair<int,int> b[sz];
int main()
{
	scanf("%d",&n);
	rep(i,0,n)
	{
		int x;
		scanf("%d",&x);
		b[i] = make_pair(x,n-1-i);
	}
	sort(b,b+n);
	rep(i,0,n)
	    a[b[i].second] = i+1;


	for(int k=0;k<K;k++)
		rep(i,0,sz)
			bit[k][i]=0;
	rep(i,0,n)
	{
		add(a[i],2,query(a[i],1));
		add(a[i],1,query(a[i],0));
		add(a[i],0,1);			
	}
	cout<<query(n,2)<<endl;
}