#include<bits/stdc++.h>

using namespace std;

int x1, y1, x2, y2;

int main() {
cin >> x1 >> y1 >> x2 >> y2;
if(x1 == x2) {
cout << x1 + (y1 - y2) << ' ' << y1 << ' ' << x2 + (y1 - y2) << ' ' << y2 << '\n';
}else if(y1 == y2) {
cout << x1 << ' ' << y1 + (x1 - x2) << ' ' << x2 << ' ' << y2 + (x1 - x2) << '\n';
} else if(abs(x1 - x2) != abs(y1 - y2)) {
cout << -1 << '\n';
} else {
cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << '\n';
}
}