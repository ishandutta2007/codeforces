#include<iostream>
using namespace std;

int main()
{
    int n,i,j,x,a[100],d;
    cin >> n;
    for (i=1;i<n;i++)
        for (j=1;j<n;j++)
        {
            x=i*j; d=0;
            while (x>0)
            {
               d++; a[d]=x%n; x/=n;
            }
            while (d>0)
            {
               cout << a[d]; d--;
            }
            if (j==n-1) cout << endl; 
            else cout << " ";
        }
//    system("pause");
    return 0;
}