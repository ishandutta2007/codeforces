#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

bool Capital(char ch)
{
    if (ch>='A' && ch<='Z')
    return true;
    else
    return false;
}

char arr[101];
Int aL=0;

int main()
{
    string str;
    Int i;
    Int small=0;
    
    cin>>str;
    
    for (i=0;i<str.length();i++)
    {
        arr[i+1]=str[i];
    }
    aL=str.length();
    
    //cout<<(int)'c'<<" "<<(int)'C'<<endl;
    
    for (i=1;i<=aL;i++)
    {
        if ( !Capital(arr[i]) )
        small++;
    }
    if (small>1)
    {
        cout<<str<<endl;
    }
    else if (small==1)
    {
        if (!Capital(str[0]))
        {
            for (i=1;i<=aL;i++)
            {
                if (Capital(arr[i]))
                {
                    arr[i]=arr[i]+('a'-'A');
                }
                else
                {
                    //cout<<arr[i]<<endl;
                    arr[i]=arr[i]-('a'-'A');
                    //cout<<arr[i]<<endl;
                }
            }
            for (i=1;i<=aL;i++)
            {
                printf("%c",arr[i]);
            }
            printf("\n");
            return 0;
        }
        else
        {
            cout<<str<<endl;
        }
    }
    else
    {
        for (i=1;i<=aL;i++)
        {
            if (Capital(arr[i]))
            {
                arr[i]=arr[i]+('a'-'A');
            }
            else
            {
                arr[i]=arr[i]-('a'-'A');
            }
        }
        for (i=1;i<=aL;i++)
        {
            printf("%c",arr[i]);
        }
        printf("\n");
        return 0;
    }
    return 0;
}