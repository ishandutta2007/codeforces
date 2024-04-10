#include <iostream>

using namespace std;

#define ll long long

int main(){
ll n, k, w;
cin >> k >> n >> w;

cout << max(0ll, k * w * (w + 1) / 2 - n);
}