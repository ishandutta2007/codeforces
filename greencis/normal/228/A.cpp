#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int s[3];
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    sort(s,s+4);
    if (s[0] == s[1]  && s[1] == s[2] && s[2] == s[3]) {
        cout << 3;
        return 0;
    }
    if ((s[0] == s[1] && s[1] == s[2]) || (s[0] == s[1] && s[2] == s[3]) || (s[1] == s[2] && s[2] == s[3])) {
        cout << 2;
        return 0;
    }
    if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) {
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}