#include <bits/stdc++.h>

using namespace std;
long long int n,ans1,ans2,ans3;
long long int f(long long int x)
{
    for (long long int i=2;i<=sqrt(x);i++)
    {
        if (x%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> n;
    if (f (n))
    {cout<<1<<endl<<n<<endl; return 0;}
    if (f(n-2))
    {
           cout<<2<<endl<<n-2<<" "<<2<<endl;        return 0;
    }
    for (long long int j=n;j>1;j--)
    {
        if (f(j))
        {
            ans1=j;
            break;
        }
    }
    long long int dif=n-ans1;
        if (f (dif))
        {
             cout<<2<<endl<<dif<<" "<<ans1;   }
        if (f(dif-2))
        {
            ans2=2;
            ans3=dif-2;
        }
        else
        {
            ans2=3;
            ans3=dif-ans2;
            while (!f(ans2) || !f(ans3))
            {
                ans2+=2;
                ans3-=2;
            }
        }
    cout<<3<<endl<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }