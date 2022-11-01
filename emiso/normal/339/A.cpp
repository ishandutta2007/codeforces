#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    sort(str.begin(),str.end());
    int pos = str.find_first_of("123");
    while(pos != str.size())
    {
              cout << str[pos];
              pos++;
              if(pos != str.size()) cout << "+";
    }
    return 0;
}