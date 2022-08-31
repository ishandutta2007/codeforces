#include<bits/stdc++.h>

using namespace std;

double fact(int a) {
return a ? fact(a - 1) * a : 1;
}

double choose(int n, int r) {
return fact(n) / fact(r) / fact(n - r);
}

double exp(int b, int e) {
return e ? exp(b, e - 1) * b : 1;
}

int main() {
string s,t; cin >> s >> t;
cout << fixed << setprecision(10);
int pos = 0;
for(char c : s) {
if(c == '+') pos --;
else pos++;
}
int cnt = 0;

for(char c : t) {
if(c == '+') pos ++;
else if(c == '-') pos --;
else if(c == '?') pos ++, cnt++;
}
if(pos % 2 != 0) {
cout << 0. << '\n';
return 0;
}
pos /= 2;
if(pos > cnt || pos < 0) {
cout << 0. << '\n';
return 0;
}
cout << choose(cnt, pos) / exp(2, cnt) << '\n';


}