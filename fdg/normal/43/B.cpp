#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char text[500]={0},str[500]={0};
    gets(text);
    gets(str);
    int mas[300]={0};
    for(int i=strlen(text)-1;i>=0;i--)
        mas[text[i]]++;
    for(int i=strlen(str)-1;i>=0;i--)
    {
        mas[str[i]]--;
        if (str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
        {
            if (mas[str[i]]<0)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}