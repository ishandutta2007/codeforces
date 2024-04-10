#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, p;
    cin >> k >> p;
    long long s = 0;
    for (int i = 1; i <= k; ++i) {
        string l1 = to_string(i);
        string l2 = l1;
        reverse(l1.begin(), l1.end());
        l2 += l1;
        s += stoll(l2);
    }
    cout << s % p << endl;
}