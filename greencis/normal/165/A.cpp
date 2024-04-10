#include <iostream>

using namespace std;

int n,x[205],y[205],res=0,s1,s2,s3,s4,i,j;

int main()
{
    cin>>n;
    for (i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    for (i = 0; i < n; ++i) {
        for(j = s1 = s2 = s3 = s4 = 0; j < n; ++j)
        {
            s1 |= x[i]==x[j] && y[i]<y[j];
            s2 |= x[i]==x[j] && y[i]>y[j];
            s3 |= y[i]==y[j] && x[i]<x[j];
            s4 |= y[i]==y[j] && x[i]>x[j];
        }
        res += s1 & s2 & s3 & s4;
    }
    cout << res;
    return 0;
}