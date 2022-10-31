#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void turn(vector<int> &v, vector<vector<int>> &ans, int n, bool &izs)
{
	/*cout << "Here  ";
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;*/
	if (v[0] != 0 && v[n - 1] != 0)
	{
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 0)
			{
				pos = i;
				break;
			}
		}
		vector<int> v1;
		for (int i = pos; i < n; i++)
			v1.push_back(v[i]);
		for (int i = 0; i < pos; i++)
			v1.push_back(v[i]);
		v = v1;
		v1 = {pos, n - pos};
		ans.push_back(v1);
	}
	else if (v[0] == 0)
	{
		int in = 0, pos = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] != i)
			{
				in = i;
				break;
			}
		}
		if (in == 0)
			izs = true;
		else
		{
			for (int i = 0; i < n; i++)
				if (v[i] == in)
					pos = i;
			vector<int> v1;
			for (int i = pos + 1; i < n; i++)
				v1.push_back(v[i]);
			for (int i = in; i <= pos; i++)
				v1.push_back(v[i]);
			for (int i = in - 1; i >= 0; i--)
				v1.push_back(v[i]);
			v = v1;
			v1.resize(0);
			for (int i = 0; i < in; i++)
				v1.push_back(1);
			v1.push_back(pos - in + 1);
			v1.push_back(n - pos - 1);
			ans.push_back(v1);
		}
	}
	else
	{
		int in = 0, pos = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (v[i] != n - 1 - i)
			{
				in = n - i - 1;
				//	cout<<i<<' '<<in<<' '<<n-1-i<<endl;
				break;
			}
		}
		if (in == 0)
		{
			reverse(v.begin(), v.end());
			vector<int> v1(n, 1);
			ans.push_back(v1);
		}
		else
		{
			for (int i = 0; i < n; i++)
				if (v[i] == in)
					pos = i;
			vector<int> v1;
			in=n-in-1;
		//	cout<<n<<' '<<pos<<' '<<in<<endl;
			for (int i = n-1; i > in; i--)
				v1.push_back(v[i]);
			for (int i = pos; i <=in; i++)
				v1.push_back(v[i]);
			for (int i = 0; i < pos; i++)
				v1.push_back(v[i]);
			v = v1;
			v1.resize(0);
			v1.push_back(pos);
			v1.push_back(in - pos+1);
			for (int i = in+1; i < v.size(); i++)
				v1.push_back(1);
			ans.push_back(v1);
		}
	}
}

void solve(int n, vector<int>&v)
{
	if (n == 1)
	{
		cout << 0 << endl;
	}
	else
	{
		vector<vector<int>> ans;
		bool izs = true;
		for (int i = 0; i < n; i++)
		{
			v[i]--;
			if (v[i] != i)
				izs = false;
		}
		while (!izs)
			turn(v, ans, n, izs);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			vector<int> v1;
			for (int j = 0; j < ans[i].size(); j++)
				if (ans[i][j] != 0)
					v1.push_back(ans[i][j]);
			cout << v1.size() << ' ';
			for (int j = 0; j < v1.size(); j++)
				cout << v1[j] << ' ';
			cout << endl;
		}
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
	int t = 1;
/*	vector<int>v1(6);
	for(int i =0; i<6; i++)
		v1[i]=i+1;*/
//	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n=6;
		cin>>n;
		vector<int>v(n);
		for(int i = 0; i<n; i++)
			cin>>v[i];
		solve(n,v);
		//	next_permutation(v1.begin(), v1.end());
	}
#endif

	return 0;
}