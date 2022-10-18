#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char cur;
    int col = 1;
    cur = s[0];
    for (int i = 1; i < s.length(); ++i){
        if (s[i] != cur) {
            cur = s[i];
            col = 1;
        }
        else ++col;
        if (col == 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}