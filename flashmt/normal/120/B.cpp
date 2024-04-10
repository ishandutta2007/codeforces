#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,k,a[2010];
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i], a[n+i]=a[i];
	while (!a[(k>n?k-n:k)]) k++;
	cout << (k>n?k-n:k) << endl;
}