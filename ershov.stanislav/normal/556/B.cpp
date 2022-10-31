#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int e;
    cin >> e;
    bool flag = true;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        if (i % 2) {
            if ((a + e) % n != i) {
                flag = false;
            }
        } else {
            if ((a - e + n) % n != i) {
                flag = false;
            }
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}