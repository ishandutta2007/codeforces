#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> good;
	good.push_back(4);
	good.push_back(7);
	good.push_back(44);
	good.push_back(47);
	good.push_back(74);
	good.push_back(77);
	good.push_back(444);
	good.push_back(447);
	good.push_back(474);
	good.push_back(477);
	good.push_back(744);
	good.push_back(747);
	good.push_back(774);
	good.push_back(777);
	int n;
	cin >> n;
	bool tf = false;
	for (int i = 0; i < good.size(); i++)
		if (n % good[i] == 0)
			tf = true;
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}