#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str1,str2;
    cin >> str1 >> str2;
    for(int i=0;i<str1.size();i++) str1[i] = tolower(str1[i]);
    for(int i=0;i<str2.size();i++) str2[i] = tolower(str2[i]);
    int c = str1.compare(str2);
    cout << c;
    return 0;
}