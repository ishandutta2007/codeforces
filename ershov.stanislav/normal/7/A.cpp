#include <iostream>
#include <string>

using namespace std;
string s[8];
int main()
{
    int a=0, b=0;
    for (int i=0; i<8; i++) cin >> s[i];
    for (int i=0; i<8; i++) {
        int c=1, d=1;
        for (int j=0; j<8; j++) {
            if (s[j][i]!='B')c=0;
            if (s[i][j]!='B')d=0;
        }
        a+=c; b+=d;
    }
    if (a<8&&b<8) cout << a+b;
    else cout << 8;
    return 0;
}