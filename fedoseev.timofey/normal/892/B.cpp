#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> l(n);
    for (int i = 0; i < n; ++i) cin >> l[i];
    stack <int> alive;
    alive.push(1);
    for (int i = 2; i <= n; ++i) {
        while (!alive.empty() && alive.top() >= i - l[i - 1]) alive.pop();
        alive.push(i);
    }
    cout << (int)alive.size() << endl;
}