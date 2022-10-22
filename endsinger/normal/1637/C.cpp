#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],x,y,t;
long long s;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s=t=x=0,y=1;
	for(int i=2;i<n;i++)
	{
		s+=a[i];
		if((a[i]&1)&&a[i]>1) 
			y=0;
		if(a[i]&1)
			t++;
		else
			x=1;
	}
	if(x==0&&(y==1||t==1))
		puts("-1");
	else
		printf("%lld\n",(s+t)/2);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}