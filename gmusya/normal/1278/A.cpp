#include <iostream>
#include <vector>
#include <string>

#define ll long long 
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string s, s1;
		cin >> s >> s1;
		vector <int> a(26);
		for (int i = 0; i < s.size(); i++)
			a[s[i] - 'a']++;
		bool tf = false;
		for (int l = 0; l < s1.size(); l++) {
			vector <int> b(26);
			for (int i = l; i < s1.size(); i++) {
				bool tf1 = true;
				b[s1[i] - 'a']++;
				for (int j = 0; j < 26; j++)
					if (b[j] != a[j])
						tf1 = false;
				if (tf1)
					tf = true;
			}
		}
		if (tf)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}