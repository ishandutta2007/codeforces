#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int u=0,z=0,prerigo=0,i;
    for(i=0;i<str.length();i++)
    {
                               if(str[i]=='0')
                               {
                                             u=0;
                                             z++;
                                             if(z>=7) prerigo=1;
                               }
                               else
                               { 
                                             z=0;
                                             u++;
                                             if(u>=7) prerigo=1;
                               }
    }
    if(prerigo==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}