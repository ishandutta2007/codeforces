#include <iostream>
#include <string>
using namespace std;

string HQ(string s){
	string ans = "";
	for (int i=0; i<s.length(); ++i){
		if (s[i] == 'H'){
			ans += 'H';
		}else {
			ans += s;
		}
	}
	return ans;
}

bool judge(string s){
	int h = 0, q = 0, a, b;
	for (int i=0; i<s.length(); ++i){
		if (s[i] == 'H') h ++;
		else q ++;
	}
	if (q == 0) return true;
	for (b=0; b*b < q; ++b);
	if (b * b != q) return false;
	for (a=0; a*b+a < h; ++a);
	if (a * b + a != h) return false;
	int len = a + b;
	for (a=0; s[a]!='Q'; ++a);
	if (a & 1) return false;
	string sa = s.substr(a/2, len);
	return HQ(sa) == s;
}

int main(){
	string in;
	cin >> in;
	if (judge(in)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}