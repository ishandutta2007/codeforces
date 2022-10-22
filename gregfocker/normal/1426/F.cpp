#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=(int)1e9+7;
int add(int a,int b)
{
        a+=b;
        if(a>=M)
                return a-M;
        if (a<0)
                return a+M;
        return a;
}

int mul(int a,int b)
{
        return a*(ll) b%M;
}

int pw(int a, int b)
{
        int r=1;
        while (b)
        {
                if (b&1)
                        r=mul(r,a);
                a=mul(a,a);
                b/=2;
        }
        return r;
}

int dv(int a, int b)
{
        return mul(a,pw(b,M-2));
}

const int N=(int)2e5+7;
int n;
string s;
ll a[3];
ll ab[3];

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);


        cin>>n>>s;
        s="."+s;
        int tot=0;
        for (int i=1;i<=n;i++)
                tot+=(s[i]=='?');
        int sol=0;
        for (int i=1;i<=n;i++)
        {
                if (s[i]=='c')
                {
                        for (int i=0;i<=2;i++)
                        {
                                sol=add(sol,mul(ab[i]%M,pw(3,tot-i)));
                        }
                }
                if (s[i]=='?')
                {
                        for (int i=0;i<=2;i++)
                        {
                                sol=add(sol,mul(ab[i]%M,pw(3,tot-i-1)));
                        }
                }
                if (s[i]=='b')
                {
                        for (int i=0;i<=2;i++)
                                ab[i]+=a[i];
                }
                if (s[i]=='?')
                {
                        for (int i=1;i<=2;i++)
                                ab[i]+=a[i-1];
                }
                if (s[i]=='a')
                        a[0]++;
                if (s[i]=='?')
                        a[1]++;
        }
        cout<<sol<<"\n";
}