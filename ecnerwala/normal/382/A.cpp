#include<iostream>
#include<string>

using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s3;
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] == '|') {
			s2 = s1.substr(i + 1);
			s1 = s1.substr(0, i);
			break;
		}
	}
	cerr << s1 << '\n' <<  s2 << '\n';
	int num = s1.size() + s2.size() + s3.size();
	if(num % 2 != 0) {
		cout << "Impossible" << '\n';
		return 0;
	}
	num /= 2;
	if(s1.size() > num || s2.size() > num) {
		cout << "Impossible" << '\n';
		return 0;
	}
	s2 += (s3.substr(num - s1.size()));
	s1 += (s3.substr(0, num - s1.size()));
	cout << s1 << '|' << s2 << '\n';
	return 0;
}