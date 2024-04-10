#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    if (s.size() % k != 0) {cout<<"NO"; return 0;}
    bool good = true;
    for (int i = 0; i < k;  ++i) {
        for (int j = 0; j < s.size() / k; ++j) {
            good &= (s[s.size() / k * i + j] == s[s.size() / k * (i+1) - 1 - j]);
        }
    }
    if (good) cout << "YES"; else cout << "NO";
    return 0;
}