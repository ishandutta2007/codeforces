#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    str[0] = toupper(str[0]);
    cout << str;
    return 0;
}