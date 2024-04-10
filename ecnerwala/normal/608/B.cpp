#include<bits/stdc++.h>
using namespace std;

int main() {
string a, b;
cin >> a >> b;
int cnt0 = 0, cnt1 = 0;
for(int i = 0; i + a.size() < b.size(); i++) {
if(b[i] == '0') cnt0++;
else if(b[i] == '1') cnt1++;
else assert(false);
}
long long res = 0;
for(int i = 0; i < a.size(); i++) {
if(b[(b.size() - a.size()) + i] == '0') cnt0++;
else cnt1++;
if(a[i] == '0') res += cnt1;
else res += cnt0;
if(b[i] == '0') cnt0--;
else cnt1--;
}
cout << res << '\n';
}