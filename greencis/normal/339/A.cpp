#include <iostream>
#include <algorithm>
using namespace std;

int numbs[101]={},curidx = 0;

int main()
{
    string s;
    cin>>s;
    for (int i = 0; i < s.length();i+=2)
        numbs[curidx++] = s[i]-'0';
    sort(numbs,numbs+curidx);
    bool first = true;
    for (int i = 0; i < curidx; ++i) {
        if (!first) cout << '+';
        cout << numbs[i];
        first = false;
    }
    return 0;
}