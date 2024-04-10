#include <iostream>
#include <vector>

using namespace std;

int ask(int x, int y) {
  cout << "? " << x + 1 << ' ' << y + 1 << endl;
  int a;
  cin >> a;
  return a;
}

int main() {
  int n;
  cin >> n;
  vector <int> arr(n, -1);
  int id = 0;
  for (int i = 1; i < n; i++) {
    int a = ask(id, i), b = ask(i, id);
    if (a > b) {
      arr[id] = a;
      id = i;
    } else {
      arr[i] = b;
    }
  }
  vector <bool> used(n + 1);
  for (int i = 0; i < n; i++)
    if (arr[i] != -1)
      used[arr[i]] = true;
  int unused = 1;
  while (used[unused])
    unused++;
  for (int i = 0; i < n; i++)
    if (arr[i] == -1)
      arr[i] = unused;
  cout << "! ";
  for (auto &now : arr)
    cout << now << ' ';
  return 0;
}