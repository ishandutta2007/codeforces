#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
#define inf 1000000000
string s;
int main(){
	cin >> s;
	for (int i=0; i<s.length(); i++) if (s[i]=='0') {
		for (int j=0; j<i; j++) cout << s[j];
		for (int j=i+1; j<s.length(); j++) cout << s[j];
		return 0;
	}
	for (int j=0; j<s.length()-1; j++) cout << s[j];
	return 0;
}