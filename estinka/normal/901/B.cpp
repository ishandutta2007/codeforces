#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> add(vector<int> p1, vector<int> p2)
{
	while (p1.size() < p2.size()) p1.push_back(0);
	while (p1.size() > p2.size()) p2.push_back(0);
	for (int i = 0; i < p1.size(); i++) p1[i] = p1[i] ^ p2[i];
	return p1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> p1(1, 1), p2(1, 1);
	p2.insert(p2.begin(), 0); // p2 > p1
	for (int i = 0; i < n - 1; i++)
	{
		vector<int> p3 = p2;
		p3.insert(p3.begin(), 0);
		vector<int> tmp1 = p1;
		p1 = p2;
		p2 = add(tmp1, p3);
	}
	cout << p2.size() - 1 << "\n";
	for (int i = 0; i < p2.size(); i++) cout << p2[i] << " ";
	cout << "\n" << p1.size() - 1 << "\n";
	for (int i = 0; i < p1.size(); i++) cout << p1[i] << " ";
	cout << "\n";
	return 0;
}