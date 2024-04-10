#include <iostream>
#include <set>

using namespace std; 

int main()
{
	long long n; cin >> n;
	set <long long> div1;
	for (long long i = 1; i * i <= n; i++)
		if (n % i == 0)
			div1.insert(i),
			div1.insert(n / i);
	
	pair <long long, long long> res = {-1, -1};

	for (auto i: div1)
	{                          
		for (auto j: div1)
		{
			long long x = i * j, y = n * n / x;
			long long a = (x+y) / 2, b = (y-x) / 2; 
			if (a-b == x && a+b == y && a > 0 && b > 0)
			{
				res = {a, b};
				break;
			}  	
		
		} 
		if (res.first > 0) break;
	}
	if (res.first < 0)
		cout << "-1" << endl;
	else
		cout << res.first << " " << res.second << endl;
}