#include<iostream>
#include<fstream>
using namespace std;

int i,cnt;
char c[12345];

int main()
{
    scanf("%s",&c);
    for(i=0;c[i];i++)
    {
        if(c[i]=='o')cnt++;
    }
    if(cnt==0)
    {
        printf("YES");
    }
    else if(i%cnt)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}