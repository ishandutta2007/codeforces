#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

void trace(int a, int b, int blockA, int blockB, int remainder, int each)
{
	if (!blockA && !blockB) return;
	
	if (!blockA)
	{
		while (b--) cout << 'x';
		return;
	}
	
	if (!blockB)
	{
		while (a--) cout << 'o';
		return;
	}
	
	if (blockA == blockB)
	{
		if (blockA == 1) 
		{
			while (a--) cout << 'o';
			trace(0, b, 0, blockB, remainder, each);
			return;
		}
		
		cout << 'o';
		trace(a - 1, b, blockA - 1, blockB, remainder, each);
		return;
	}
	
	for (int i = 0; i < each; i++) cout << 'x', b--;
	if (blockB <= remainder) cout << 'x', b--;
	trace(a, b, blockA, blockB - 1, remainder, each);
}

int main()
{
	ios::sync_with_stdio(0);
	
	int a, b, ansBlockA, ansBlockB;
	long long ans = -oo;
	cin >> a >> b;
	
	if (!b)
	{
		cout << 1LL * a * a << endl;
		while (a--) cout << 'o';
		return 0;
	}
	
	if (!a)
	{
		cout << - 1LL * b * b << endl;
		while (b--) cout << 'x';
		return 0;
	}
	
	for (int blockB = 1; blockB <= b; blockB++)
	{
		int blockA = max(1, blockB - 1);
		if (blockA > a) continue;
		
		int remainder = b % blockB, each = b / blockB;
		long long score = blockA - 1 + (a - blockA + 1LL) * (a - blockA + 1);
		score -= 1LL * each * each * (blockB - remainder) + (each + 1LL) * (each + 1) * remainder;
		
		if (score > ans)
		{
			ans = score;
			ansBlockB = blockB;
			ansBlockA = blockA;
		}
	}
	
	cout << ans << endl;
	trace(a, b, ansBlockA, ansBlockB, b % ansBlockB, b / ansBlockB);
}