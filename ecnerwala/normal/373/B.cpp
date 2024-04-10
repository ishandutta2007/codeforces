#include<iostream>

using namespace std;

typedef long long ll;

int main () {
ll w, m, k; cin >> w >> m >> k;
w /= k;
ll cnt = 0;
for(ll i = 1, p = 1; w; i++, p *= 10) {
if(m < p * 10) {
ll num = p * 10 - m;
if(num * i < w) {
w -= num * i;
cnt += num;
m = p*10;
}else {
cnt += w/i;
break;

}
}
}

cout << cnt << '\n';

return 0;
}