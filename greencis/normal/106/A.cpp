#include <iostream>
#include <map>
using namespace std;
map<char,int> mp;
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    mp['6'] = 1;
    mp['7'] = 2;
    mp['8'] = 3;
    mp['9'] = 4;
    mp['T'] = 5;
    mp['J'] = 6;
    mp['Q'] = 7;
    mp['K'] = 8;
    mp['A'] = 9;

    if (b[1] == a[0]) {
        if (c[1] == a[0]) {
            cout << (mp[b[0]] > mp[c[0]] ? "YES" : "NO");
        } else {
            cout << "YES";
        }
    } else {
        if (b[1] == c[1]) {
            cout << (mp[b[0]] > mp[c[0]] ? "YES" : "NO");
        } else {
            cout << "NO";
        }
    }

    return 0;
}