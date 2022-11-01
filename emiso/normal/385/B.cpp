#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    int npos=0,pos,c=0;
    pos = s1.find("bear");
    while(pos != -1)
    {
              c += ((pos+1)-npos)*(s1.size()-(pos+3));
              npos=pos+1;
              pos = s1.find("bear",npos);
    }
    cout << c;
    return 0;
}