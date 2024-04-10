#include <iostream>

using namespace std;

int n,a[100005],t25,t50,q;

int main()
{
    cin >> n;
    while(n--) {
        cin >> q;
        if (q == 25) {
            ++t25;
        } else if (q == 50) {
            if (t25 <= 0) {
                cout << "NO";
                return 0;
            } else --t25, ++t50;
        } else {
            if (t50 > 0) {
                if (t25 <= 0) {
                    cout << "NO";
                    return 0;
                } else {
                    --t50;
                    --t25;
                }
            } else {
                if (t25 <= 2) {
                    cout << "NO";
                    return 0;
                }
                else t25 -= 3;
            }
        }
    }
    cout << "YES";
    return 0;
}