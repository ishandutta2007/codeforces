#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string a;
    int b;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (cin>>a>>b)
    {
        if (a=="front")
        {
            if (b==1) cout<<"L\n";else cout<<"R\n";
        }
        else
        {
            if (b==1) cout<<"R\n"; else cout<<"L\n";
        }
    }
    return 0;
}