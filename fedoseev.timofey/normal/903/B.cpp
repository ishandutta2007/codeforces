#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector <string> strategy;
    while (true) {
        if (h2 - a1 <= 0) {
            strategy.push_back("STRIKE");
            break;
        }
        if (h1 - a2 <= 0) {
            h1 += c1;
            strategy.push_back("HEAL");
        }
        else {
            h2 -= a1;
            strategy.push_back("STRIKE");
        }
        h1 -= a2;
    }
    cout << strategy.size() << endl;
    for (auto s : strategy) {
        cout << s << endl;
    }
}