#include<bits/stdc++.h>
using namespace std;
long long n,i,a[1000000],x,y,ma1,ma2;
double r1,r2;
void swa()
{
	int te;
	te=x;
	x=y;
	y=te;
}
int main()
{
	cin>>n>>x>>y;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	if(x>y)
		swa();
	for(i=0;i<x;i++)
	{
		ma1=ma1+a[i];
	}
	for(i=x;i<x+y;i++)
	{
		ma2=ma2+a[i];
	}
	r1=(float)ma1/x;
	r2=(float)ma2/y;
	cout<<fixed<<setprecision(10)<<r1+r2<<endl;
	return 0;
}