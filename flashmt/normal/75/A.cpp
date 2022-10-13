#include<iostream>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int a,b,c;

void edit(int &a)
{
    int p=1,aa=0;
    while (a)
    {
       if (a%10) aa+=(a%10)*p,p*=10;
       a/=10;   
    } 
    a=aa;
}

int main()
{
    cin >> a >> b;
    c=a+b;
    edit(a);
    edit(b);
    edit(c);
    if (c==a+b) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}