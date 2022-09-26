#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

int q;
long long n,k;
long long size[100005];

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string f10 = "What are you doing while sending \"";
string f11 = "\"? Are you busy? Will you send \"";
string f12 = "\"?";

char solve(long long a,long long b)
{
	if (a == 0)
		return b > f0.size() ? '.' : f0[b - 1];
	if (b <= f10.size())
		return f10[b - 1];
	b -= f10.size();
	if (b <= size[a - 1])
		return solve(a - 1,b);
	b -= size[a - 1];
	if (b <= f11.size())
		return f11[b - 1];
	b -= f11.size();
	if (b <= size[a - 1])
		return solve(a - 1,b);
	b -= size[a - 1];
	if (b <= f12.size())
		return f12[b - 1];
	return '.';
}

int main()
{
	size[0] = f0.size();
	for (int i = 1;i <= 100000;i++)
	{
		size[i] = 2ll * size[i - 1] + (long long)f10.size() + (long long)f11.size() + (long long)f12.size();
		if (size[i] >= 1000000000000000000)
			size[i] = 1000000000000000001;
	}
	cin >> q;
	for (int i = 1;i <= q;i++)
	{
		cin >> n >> k;
		cout << solve(n,k);
	}
	cout << endl;
	return 0;
}