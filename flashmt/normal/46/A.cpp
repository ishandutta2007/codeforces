#include<iostream>
#include<algorithm>
#include<cmath>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int n;

int main()
{
    cin >> n;
    int x=1,i;
    fr(i,1,n-1)
    {
       x+=i;
       if (x>n) x-=n;
       cout << x << " ";
    }
    cout << endl;
//    system("pause");
    return 0;
}