#include<iostream>
#include<algorithm>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int main()
{
    int n,x=0,y=0,z=0,xx,yy,zz;
    cin >> n;
    while (n--)
    {
          cin >> xx >> yy >> zz;
          x+=xx; y+=yy; z+=zz;
    }
    if (!x && !y && !z) cout << "YES" << endl;
    else cout << "NO" << endl;
//    system("pause");
    return 0;
}