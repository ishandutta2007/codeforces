#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;
typedef long long ll;
ll pdMaior[ms];
ll pdMenor[ms];
ll a[ms];

int main() {
  int n;
  cin >> n;
  int menor = 0;
  int maior = 0;
  ll sum = 0;
  int qntNeg = 0, qntPos = 0;
  for(int i = 0; i< n; i++) {
    cin >> a[i];
    if(a[i] < 0) qntNeg++;
    if(a[i] < a[menor]) {
      menor = i;
    }
    if(a[i] > 0) qntPos++;
    if(a[i] > a[maior]) {
      maior = i;
    }
    sum += abs(a[i]);
  }
  if(n == 1) {
    cout << a[0] << endl;
  } else if(n == 2) {
    cout << max(a[0] - a[1], a[1] - a[0]) << endl;
  } else if(qntNeg == 0) {
    cout << sum - 2 * a[menor] << endl;
  } else if(qntPos == 0) {
    cout << 2 * a[maior] + sum;
  } else {
    cout << sum << endl;
  }
  return 0;
}