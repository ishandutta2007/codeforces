#include<iostream>
#include<string>

using namespace std;

bool wins(char a, char b) {
if(a == '8' && b == '[') return true;
if(a == '[' && b == '(') return true;
if(a == '(' && b == '8') return true;
return false;
}

int main() {
string s1, s2; cin >> s1 >> s2;
int n1 = 0;
int n2 = 0;
for(int i = 0; i < s1.size(); i += 2) {
if(s1[i] == s2[i]) continue;
if(wins(s1[i], s2[i])) n1++;
else n2++;
}
if(n1 > n2) cout << "TEAM 1 WINS" << '\n';
else if(n1 < n2) cout << "TEAM 2 WINS" << '\n';
else cout << "TIE" << '\n';
}