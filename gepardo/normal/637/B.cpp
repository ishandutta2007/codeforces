#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL);
	map <string, bool> m;
	int n; cin >> n;
	vector <string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = n - 1; i >= 0; i--)
		if (!m[v[i]])
		{
			cout << v[i] << "\n";
			m[v[i]] = true;
		} 
}