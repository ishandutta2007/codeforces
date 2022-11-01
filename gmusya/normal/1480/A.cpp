#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);	
  int t;
  cin >> t;
  while (t--) {
  	string s;
  	cin >> s;
  	for (int i = 0; i < (int) s.size(); i++) {
  	  if (i % 2 == 0) {
  	  	if (s[i] == 'a')
  	  	  s[i]++;
  	  	else
  	  	  s[i] = 'a';  	
  	  }	else {
        if (s[i] == 'z')
          s[i]--;
        else
          s[i] = 'z'; 	
  	  }
  	}
  	cout << s << '\n';
  }
}