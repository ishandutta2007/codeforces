#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],b[N],s,t;
bitset<N*N*2>f;
void sol()
{
	scanf("%d",&n);
	s=t=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		t+=(n-2)*(a[i]*a[i]+b[i]*b[i]);
		s+=a[i]+b[i];
	}
	f=1;
	for(int i=1;i<=n;i++)
		f=(f<<a[i])|(f<<b[i]);
	for(int i=s/2;i<=s;i++)
	{
		if(f[i])
		{
			t=(t+i*i+(s-i)*(s-i));
			break;
		}
	}
	printf("%d\n",t);
}
int main()
{
	int z;
	scanf("%d",&z);
	while(z--)
		sol();
	return 0;
}