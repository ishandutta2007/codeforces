/*input
13
1 3 5 2 2 3 5 1 2 2 1 3 5
*/
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	long long mas[n];
	long long op = 0;
	cin >> mas[0];
	long long gc = mas[0];
	mas[0] &= 1;

	for (int i = 1; i < n; i++) {
		cin >> mas[i];
		gc = __gcd(mas[i], gc);
		mas[i] &= 1;
	}

	if (gc != 1) {
		cout << "YES\n0\n";
		return 0;
	}

	vector<int> kiekiai[2];

	int po = 0;
	int sk = 0;
	int kiek = 0;

	while (po < n) {
		if (mas[po] != sk) {
			kiekiai[sk].push_back(kiek);
			kiek = 0;
			sk ^= 1;
		}

		po++;
		kiek++;
	}

	kiekiai[sk].push_back(kiek);

	if (kiekiai[0].size() > kiekiai[1].size())
		kiekiai[0].pop_back();

	/*for (auto && i : kiekiai[0])
		cout << i << " ";

	cout << endl;

	for (auto && i : kiekiai[1])
		cout << i << " ";

	cout << endl;*/

	for (int i = 0; i < kiekiai[1].size(); i++)
		op += kiekiai[1][i] / 2 + (kiekiai[1][i] % 2) * 2;


	cout << "YES\n";
	cout << op << endl;

	return 0;
}