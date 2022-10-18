#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] += ('A'-'a');
    cout<<s;
    return 0;
}