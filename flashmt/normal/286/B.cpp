#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[2000100], n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) a[i] = i + 1;
	
	for (int i = 2, shift = 0; i <= n; i++, shift++)
	{
		int last = n - n % i;
		a[n + shift] = a[last + shift];
		for (int j = last; j >= i; j -= i)
			a[j + shift] = a[j - i + shift];
	}
	
	for (int i = 0; i < n; i++) printf("%d ", a[i + n - 1]);
}