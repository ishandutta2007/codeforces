#include<iostream>
#include<algorithm>
#include<cmath>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

double n,v,a[111];

int main()
{
    int i;
    double s,t,x,y=0;
    cin >> n >> v;
    fr(i,1,n) 
    {
       cin >> a[i]; y+=a[i];
    }
    s=v/y;
    fr(i,1,n) 
    {
        cin >> x;
        t=x/a[i]; 
        s=min(s,t);
    }   
    s*=y;
    cout << s << endl;
    return 0;
}