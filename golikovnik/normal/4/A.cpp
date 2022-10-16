#include <iostream>

using namespace std;

int main() {
    int w;
    cin >> w;
    string ans;
    if ((w % 2 == 1) || (w == 2)) {
        ans = "NO";
    } else {
        ans = "YES";
    }
    cout << ans << endl;
    return 0;
}