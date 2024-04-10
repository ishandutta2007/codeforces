#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M=(int) 1e9+7;

int add(int a,int b)
{
        a+=b;
        if (a>=M)
                return a-M;
        if (a<0)
                return a+M;
        return a;
}

int mul(int a,int b)
{
        return a*(ll)b%M;
}

int pw(int a,int b)
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

int dv(int a,int b)
{
        return mul(a,pw(b,M-2));
}

const int N=(int) 1e5+7;
int n,a[N],pre[N],suf[N],p10[N],sup[N];
string s;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        p10[0]=1;
        sup[0]=1;
        for (int i=1;i<N;i++)
                p10[i]=mul(p10[i-1],10),sup[i]=add(sup[i-1],p10[i]);


        cin>>s;
        n=(int) s.size();
        for (int i=1;i<=n;i++)
                a[i]=s[i-1]-'0';
        pre[1]=a[1];
        for (int i=2;i<=n;i++)
        {
                pre[i]=add(mul(pre[i-1],10),a[i]);
        }
        suf[n]=a[n];
        for (int i=n-1;i>=1;i--)
        {
                suf[i]=add(suf[i+1],mul(p10[n-i],a[i]));
        }
        /**for (int i=1;i<=n;i++)
        {
                cout<<i<<" : "<<pre[i]<< " "<<suf[i]<<"\n";
        }**/
        int sol=0;
        for (int r=1;r<=n;r++)
        {
                sol=add(sol,mul(suf[r+1],r));
        }
        for (int l=1;l<=n;l++)
        {
                int cur=0;
                cur=sup[n-l];
                sol=add(sol,mul(cur,pre[l-1]));
        }
        cout<<sol<<"\n";
}