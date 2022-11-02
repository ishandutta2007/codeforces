#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> arr(n);
  {
    int ab, ac, bc;
    cout << "XOR 1 2 " << endl;
    int k = 0;

    int x;
    cin >> x;
    k ^= x;
    cout << "AND 1 2 " << endl;
    int y;
    cin >> y;
    ab = x + 2 * y;

    cout << "XOR 1 3 " << endl;
    cin >> x;
    k ^= x;
    cout << "AND 1 3 " << endl;
    cin >> y;
    ac = x + 2 * y;

    cout << "AND 2 3" << endl;
    cin >> y;
    bc = k + 2 * y;
    
    arr[0] = (ab + ac - bc) / 2;
    arr[1] = (ab + bc - ac) / 2;
    arr[2] = (ac + bc - ab) / 2;
  }
  for (int i = 3; i < n; i++) {
    cout << "XOR 1 " << i + 1 << endl;
    int x;
    cin >> x;
    arr[i] = (arr[0] ^ x);
  }
  cout << "! ";
  for (auto &now : arr)
    cout << now << ' ';
  return 0;
}