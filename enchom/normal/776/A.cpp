#include <iostream>
#include <stdio.h>
using namespace std;

string A,B;
int n;

int main()
{
    int i;
    string C,D;

    cin>>A>>B;

    cout<<A<<" "<<B<<endl;

    cin>>n;

    for (i=1;i<=n;i++)
    {
        cin>>C>>D;

        if (C==A)
        A=D;
        else
        B=D;

        cout<<A<<" "<<B<<endl;
    }

    return 0;
}