#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int pos = str.find("WUB");
    while(pos != -1)
    {

              str.erase(pos,3);
              int ans = pos;
              pos = str.find("WUB",pos);
              if(ans!=0 && ans!=pos) {
                         str.insert(ans," ");
                         if (pos!=-1) pos++;
                         }
    }
    cout << str;
    return 0;
}