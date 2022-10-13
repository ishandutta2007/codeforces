#include<iostream>
#include<algorithm>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int n,m,f[1111],g[1111];

int main()
{
    int i,l,r,t,c,re=0;
    cin >> n >> m;
    fr(i,1,n) f[i]=1111;
    while (m--)
    {
       cin >> l >> r >> t >> c;
       fr(i,l,r)
         if (f[i]>t)
         {
            f[i]=t; 
            g[i]=c;
         }   
    }
    fr(i,1,n) re+=g[i];
    cout << re << endl;
    //system("pause");
    return 0;
}