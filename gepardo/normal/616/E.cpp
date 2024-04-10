#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int mod = (int)1e9 + 7;


int mulMod(int a, int b)
{
		a %= mod;
		b %= mod;
		return (a * b) % mod;
}


int div2Mod(int a)
{
		if (a % 2 == 1) a += mod;
		return a / 2;
}

main()
{
	int n, m; cin >> n >> m;
	//for (int i = 1; i <= m; i++) cout << n / i << " "; cout << endl;
	//for (int i = 1; i <= m; i++) cout << n % i << " "; cout << endl;
	// int n, m; cin >> n >> m;
	int ans = 0;
	if (m > n)
	{
		ans = mulMod(n, m - n);
		m = n;
	} 
	for (int i = 1; i <= m; i++)
	{
		int curDiv = n / i, leftRange = n / (curDiv + 1) + 1, rightRange = n / curDiv;
		if (leftRange > rightRange) leftRange =  rightRange;
		leftRange = min(m, leftRange);
		rightRange = min(m, rightRange);
		int leftMod = n % leftRange, rightMod = n % rightRange, cnt = rightRange - leftRange + 1;
		int addTo = div2Mod(mulMod(cnt, leftMod + rightMod));
	  ans = (ans + addTo) % mod;	
	 
		//cout << " " << curDiv << " " << leftRange << " " << rightRange << endl;
		i = rightRange;
	}	
	cout << ans;

}