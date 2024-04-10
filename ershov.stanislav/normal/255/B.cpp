#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string s;
int x, y;
int main(){
	cin >> s;
	for (int i=0; i<s.length(); i++) if (s[i]=='x') x++; else y++;
	for (int i=0; i<abs(x-y); i++) cout << ((x>y)?'x':'y');
    return 0;
}