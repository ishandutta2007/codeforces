
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

using ll = long long;
using ull = unsigned long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> poses;
	int cur = 0, mx = 2 * n - 1,  l=0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{
			l=1;
			poses.push_back(i);
			cur++;
			if (i > 0 && s[i - 1] == 'W')
				cur++;
		}
	}
	if(l==1)
	{
		vector<int> holes;
		for (int i = 1; i < poses.size(); i++)
		{
			int cr = poses[i] - poses[i - 1] - 1;
			if (cr > 0)
				holes.push_back(cr);
		}
		sort(holes.begin(), holes.end());
		cur += 2 * k;
		int sum = 0;
		for (int i = 0; i < holes.size(); i++)
		{
			sum += holes[i];
			if (sum <= k)
				cur++;
		}
		cout << min(cur, mx) << endl;
	}
	else{
		k=min(k,n);
		cout<<max(2*k-1,0)<<endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve();
#endif

	return 0;
}