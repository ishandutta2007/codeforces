#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int step = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (step == 0) {
            if (s[i] == 'h') {
                ++step;
            }
        } else if (step == 1) {
            if (s[i] == 'e') {
                ++step;
            }
        } else if (step == 2) {
            if (s[i] == 'l') {
                ++step;
            }
        } else if (step == 3) {
            if (s[i] == 'l') {
                ++step;
            }
        } else if (step == 4) {
            if (s[i] == 'o') {
                step=5;
                break;
            }
        }
    }
    cout << (step==5?"YES":"NO");
    return 0;
}