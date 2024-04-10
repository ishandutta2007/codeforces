#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    string a,b;
    int A=0,B=0;
    int i;
    
    cin>>a>>b;
    
    for (i=0;i<a.length();i+=2)
    {
        if (a[i]!=b[i])
        {
            if (a[i]=='8')
            {
                if (b[i]=='(')
                B++;
                else
                A++;
            }
            else if (a[i]=='(')
            {
                if (b[i]=='8')
                A++;
                else
                B++;
            }
            else
            {
                if (b[i]=='8')
                B++;
                else
                A++;
            }
        }
    }
    
    if (A>B)
    printf("TEAM 1 WINS");
    else if (A<B)
    printf("TEAM 2 WINS");
    else
    printf("TIE");
    
    cout<<endl;
    
    return 0;
}