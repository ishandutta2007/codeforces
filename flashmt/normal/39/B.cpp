#include<iostream>
using namespace std;

int main()
{
    int n,i,a[101],re,x;
    cin >> n; re=0;
    for (i=1;i<=n;i++)
    {
        cin >> x;
        if (x==re+1)
        {
           re++; a[re]=i;
        }
    }
    cout << re << endl;
    for (i=1;i<re;i++) cout << a[i]+2000 << " ";
    if (re>0) cout << a[re]+2000 << endl;
//    system("pause");
    return 0;
}