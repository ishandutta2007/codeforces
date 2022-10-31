#include <iostream>
#include<vector>
#include<fstream>
#include<set>
#include<random>
#include<queue>
#include<algorithm>
using namespace std;

using ll = long long;
using ull = unsigned long long;
void merge(vector<int>& q, vector<int>&invq, int a, int b)
{
	int val = a;
	int t = 0;
	for (int i = 0; i < q.size(); i++)
	{
		val = q[val];
		if (val == b)
		{
			t = 1;
			break;
		}
	}
	int qa = q[a], qb = q[b];
	if (t == 0)
	{
		q[a] = qb;
		q[b]=qa;
	}
	for (int i = 0; i < q.size(); i++)
		invq[q[i]] = i;
}
string reverse(string s, int a, int b)
{
	string q = s;
	for (int i = a; i < b; i++)
		q[i] = s[b - 1 - i + a];
	return q;
}
bool check(string s)
{
	int bal = 0;
	for (auto a : s)
	{
		if (a == '(')
			bal++;
		else
			bal--;
		if (bal < 0)
			return false;
	}
	return true;
}
int main()
{
	int test;
	cin >> test;
	for (int tt = 0; tt < test; tt++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (check(s))
			cout << 0 << endl;
		else
		{
			int posl = 0, ball = 0, cb=0;
			for (int i = 0; i < 2 * n; i++)
			{
				if (s[i] == '(')
					cb++;
				else
					cb--;
				if (cb > ball)
				{
					ball = cb;
					posl = i + 1;
				}
				if (cb < 0)
					break;
			}
			int posr = 2 * n, balr = 0;
			cb = 0;
			for (int i = 2*n-1; i >= 0; i--)
			{
				if (s[i] == ')')
					cb++;
				else
					cb--;
				if (cb > balr)
				{
					balr = cb;
					posr = i;
				}
				if (cb < 0)
					break;
			}
			//cout << "?! " << posl << ' ' << posr << endl;
			string s1 = reverse(s, posl, posr);
			if (check(s1))
			{
				cout << 1 << endl;
				cout << posl + 1 << ' ' << posr << endl;
			}
			else
			{
				posl = 0; 
				ball = 0;
				cb = 0;
				for (int i = 0; i < 2 * n; i++)
				{
					if (s[i] == '(')
						cb++;
					else
						cb--;
					if (cb > ball)
					{
						ball = cb;
						posl = i + 1;
					}
				}
				cout << 2 << endl;
				cout << 1 << ' ' << posl << endl;
				cout << posl + 1 << ' ' << 2 * n << endl;
			}
		}
	}
}