#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> x;
    for (int i = 1; i <= n; ++i) {
        x.push_back(i);
    }
    if (a > b) swap(a, b);
    int num = 1;
    while (true) {
        vector <int> tmp;
        for (int i = 0; i < x.size(); i += 2) {
            if (x[i] == a && x[i + 1] == b) {
                if (x.size() == 2) {
                    cout << "Final!" << endl;
                }
                else {
                    cout << num << endl;
                }
                return 0;
            }
            if (x[i] == a || x[i] == b) {
                tmp.push_back(x[i]);
            }
            else {
                tmp.push_back(x[i + 1]);
            }
        }
        x = tmp;
        ++num;
    }
}