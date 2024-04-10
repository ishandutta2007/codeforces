#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int main()
{
    string s;
    int n,i,j,a[1001],x=0,re,y;
    cin >> n;
    cin >> s;
    re=n/2;
    fr(i,0,n-1) 
       if (s[i]=='H') a[i]=0;
       else a[i]=1;
    fr(i,0,n-1) x+=a[i];
    fr(i,0,n-1)
    {
       y=x;
       fr(j,0,x-1) y-=a[(i+j)%n];
       re=min(re,y);
    }
    cout << re << endl;
//   system("pause");
    return 0;
}