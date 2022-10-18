#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll x[3],k,a,b,c;
    cin >> x[0] >> x[1] >> x[2] >> k;
    sort(x,x+3);
    if (k>=x[0]-1+x[1]-1+x[2]-1)
    {
        a=x[0]-1; b=x[1]-1; c=x[2]-1;
    }
    else
    {
        a=k/3; b=k/3; c=k/3;
        if (k%3==2) b++,c++;
        if (k%3==1) c++;
        ll free=0;
        if (a+1>x[0])
        {
            free=a-(x[0]-1);
            a=x[0]-1;
            b+=free/2;
            c+=free/2;
            if (free%2==1)
            {
                if (b==c) c++;
                else b++;
            }
        }
        if (b+1>x[1])
        {
            free=b-(x[1]-1);
            b=x[1]-1;
            c+=free;
        }
    }
    cout << (a+1)*(b+1)*(c+1) << endl;
    return 0;
}