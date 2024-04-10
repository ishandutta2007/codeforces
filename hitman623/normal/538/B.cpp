#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pair < long , long > pll
using namespace std;

int main()
{
    long n,m=0,num,i,j;
    cin>>n;
    string s;
    while(n>0)
    {
        m=max(n%10,m);
        s.pb(n%10+'0');
        n/=10;
    }
    reverse(s.begin(),s.end());
    cout<<m<<endl;
    n=s.length();
    for(j=0;j<m;++j)
    {
        num=0;
        for(i=0;i<n;++i)
        {
            if(s[i]>'0')
            {
                num=num*10+1;
                s[i]--;
            }
            else num=num*10;
        }
        cout<<num<<" ";
    }
    return 0;
}