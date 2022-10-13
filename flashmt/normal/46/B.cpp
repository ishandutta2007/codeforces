#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int main()
{
    int a[5],n,i,j;     
    string s,b[5];
    b[0]="S"; b[1]="M"; b[2]="L"; b[3]="XL"; b[4]="XXL";
    fr(i,0,4) cin >> a[i];
    cin >> n;
    while (n--)
    {
          cin >> s;
          fr(i,0,4)
             if (b[i]==s) break;
          if (a[i]) 
          {
             cout << b[i] << endl;
             a[i]--;
             continue;
          }
          fr(j,1,4)
          {
             if (i+j<5 && a[i+j]) 
             {
                cout << b[i+j] << endl;
                a[i+j]--;
                break;
             }
             if (i-j>=0 && a[i-j])
             {
                 cout << b[i-j] << endl;
                 a[i-j]--;
                 break;
             }
          }
    }
//    system("pause");
    return 0;
}