#include <iostream>
using namespace std;

int n,a,f,i1;
string s;

int main()
{
    cin>>n>>s;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == 'A') ++a;
        else if (s[i] == 'F') ++f;
        else ++i1;

    if (i1 == 0) cout << a;
    else if (i1 == 1) cout << i1;
    else cout << 0;

    return 0;
}