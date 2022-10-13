#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,k,re=0,x;
	cin >> n >> k;
	while (n--) cin >> x, re+=(x>=3*k?x-3*k:x%k);
	cout << re << endl;
}