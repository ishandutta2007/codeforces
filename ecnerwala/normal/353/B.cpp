#include<iostream>
#include<algorithm>

using namespace std;

int n;
pair<int, int> a[400];
int b[400];

int go() {
for(int i = 0; i < n; i++) a[i].second = i;
sort(a, a + n);
int n1 = 0, n2 = 0;
for(int i = 0; i < n;) {
int j;
for(j = i; j < n && a[i].first == a[j].first; j++);
int c = j - i;
if(c >= 2) {
n1 ++, n2 ++;
b[a[i].second] = 1;
b[a[i + 1].second] = 2;
}
else if(n1 < n2) {
n1++;
b[a[i].second] = 1;
}
else {
n2 ++;
b[a[i].second] = 2;
}
i=j;
}
int ans = n1 * n2;
for(int i = 0; i < n; i++) {
if(b[i]) continue;
if(n1 < n2) {
n1++;
b[i] = 1;
} else {
n2++;
b[i] = 2;
}
}
return ans;
}
int main() {
cin >> n; n *= 2;
for(int i = 0; i < n; i++) cin >> a[i].first;
cout << go() << '\n';
for(int i = 0; i < n; i++) cout << b[i] << ' '; cout << '\n';

}