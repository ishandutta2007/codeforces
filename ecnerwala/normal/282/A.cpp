#include<iostream>
#include<string>

using namespace std;

int main() {
int x, n;
cin >> n;
x = 0;
for(int i = 0; i < n; i++) {
string s;
cin >> s;
if(s[1] == '+') x ++;
else x--;
}
cout << x << '\n';
return 0;
}