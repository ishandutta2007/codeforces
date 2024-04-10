#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> first(n);
    vector <int> second(n);
    bool flag = false;
    int ans = 0;
    vector <int> one;
    for (int i = 0; i < n; ++i) {
        cout << "? " << 0 << " " << i << endl;
        fflush(stdout);
        cin >> first[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << "? " << i << " " << 0 << endl;
        fflush(stdout);
        cin >> second[i];
    }
    for (int fb = 0; fb < n; ++fb) {
        vector <int> b(n);
        vector <int> p(n);
        b[0] = fb;
        p[0] = first[0] ^ fb;
        for (int i = 1; i < n; ++i) {
            b[i] = second[i] ^ p[0];
            p[i] = first[i] ^ b[0];
        }
        bool f = true;
        for (int i = 0; i < n; ++i) {
            if (p[b[i]] != i) {
                f = false;
                break;
            }
        }
        if (f) {
            ++ans;
            if (!flag) {
                flag = true;
                one = b;
            }
        }
    }
    cout << "! " << ans << endl;
    for (auto elem : one) {
        cout << elem << " ";
    }
}