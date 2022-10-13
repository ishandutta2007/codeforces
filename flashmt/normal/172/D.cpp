#include <iostream>
using namespace std;

int f[10000100];

int main()
{
	for (int i=1;i<=10000000;i++) f[i]=1;
	for (int i=2;i*i<=10000000;i++)
		for (int j=i*i;j<=10000000;j+=i*i)
			f[j]=max(f[j],i*i);
	
	int a,n;
	long long ans=0;
	cin >> a >> n;
	n+=a;
	while (a<n)	ans+=a/f[a], a++;
	cout << ans << endl;
}