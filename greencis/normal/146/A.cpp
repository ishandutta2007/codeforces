#include <iostream>

using namespace std;
int n,s1,s2;
int main()
{

    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '4' && s[i] != '7') {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < n/2; ++i)
        s1 += s[i];
    for (int i = n/2; i < n; ++i)
        s2 += s[i];

    cout << (s1 == s2 ? "YES": "NO");
}