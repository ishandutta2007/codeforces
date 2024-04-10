#include<bits/stdc++.h>
using namespace std;

int main() {
string str; cin >> str;
long long v = (str[0] - '0'); v *= 10;
v += (str[2] - '0'); v *= 10;
v += (str[4] - '0'); v *= 10;
v += (str[3] - '0'); v *= 10;
v += (str[1] - '0');
long long res = v;
res *= v; res %= 100000;
res *= v; res %= 100000;
res *= v; res %= 100000;
res *= v; res %= 100000;
cout << res / 10000; res %= 10000;
cout << res / 1000; res %= 1000;
cout << res / 100; res %= 100;
cout << res / 10; res %= 10;
cout << res << '\n';
}