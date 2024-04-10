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

int main()
{
	int test;
	cin >> test;
	for (int tt = 0; tt < test; tt++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		string s;
		cin >> s;
		int n = s.length();
		int acount = 0, bcount = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'A')
				acount++;
			else
				bcount++;
		}
		if (acount != a + c + d)
		{
			cout << "NO \n";
			continue;
		}
		vector<int>poses;
		poses.push_back(0);
		for (int i = 0; i < s.length() - 1; i++)
			if (s[i] == s[i + 1])
				poses.push_back(i + 1);
		poses.push_back(n);
		int cnt=0;
		vector<int>atype, btype;
		for (int j = 0; j < poses.size() - 1; j++)
		{
			cnt += (poses[j + 1] - poses[j] - 1) / 2;
			if ((poses[j + 1] - poses[j]) % 2 == 0)
			{
				if (s[poses[j]] == 'A')
					atype.push_back((poses[j + 1] - poses[j]) / 2);
				else
					btype.push_back((poses[j + 1] - poses[j]) / 2);
			}
		}
		sort(atype.begin(), atype.end());
		sort(btype.begin(), btype.end());
		int asum = 0, aval=0;
		for (int i = 0; i < atype.size(); i++)
		{
			asum += atype[i];
			if (asum <= c)
				aval++;
		}
		int bsum = 0, bval = 0;
		for (int i = 0; i < btype.size(); i++)
		{
			bsum += btype[i];
			if (bsum <= d)
				bval++;
		}
	//	cout << cnt << ' ' << aval << ' ' << bval << endl;
		if (aval + bval + cnt >= c + d)
			cout << "YES \n";
		else
			cout << "NO \n";
	}
}