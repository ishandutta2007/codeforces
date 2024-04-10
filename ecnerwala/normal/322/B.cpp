#include<iostream>

using namespace std;

int main() {
int a, b, c;
cin >> a >> b >> c;
int out = 0;
for(int i = 0; i < 3 && i <= a && i <= b && i <= c; i++) {
int v = (a-i) / 3 + (b-i) / 3 + (c-i) / 3 + i;
if(v > out) out = v;
}
cout << out << '\n';
return 0;
}