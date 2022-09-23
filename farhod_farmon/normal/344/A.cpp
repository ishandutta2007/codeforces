#include <iostream>
using namespace std;
int main ()
{
    int a,b[100000],c=0,i;
    cin>>a;
    for(i=0; i<a; i++)
    {
        cin>>b[i];
        }
    for(i=0; i<a; i++)
    {
        if (b[i]!=b[i+1]){c++;}
        }
        cout<<c;
    return 0;
    }