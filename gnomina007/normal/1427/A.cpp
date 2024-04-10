
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll = long long;
using ull = unsigned long long;


bool ch(vector<int>v)
{
	int sum=0;
	for(int i = 0; i<v.size(); i++)
	{
		sum+=v[i];
		if(sum==0)
			return false;
	}
	return true;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	if(ch(v))
	{
		cout<<"YES"<<endl;
		for(int i=0; i<n; i++)
			cout<<v[i]<<' ';
		cout<<endl;
	}
	else{
		reverse(v.begin(), v.end());
		if(ch(v))
		{
			cout<<"YES"<<endl;
			for(int i=0; i<n; i++)
				cout<<v[i]<<' ';
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
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
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve();
#endif

	return 0;
}