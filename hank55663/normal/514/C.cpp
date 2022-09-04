#define N 655360
#define M 1000000000007LL
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ba[700000]={1};
int main()
{
    for(ll i=1;i<700000;i++)
        ba[i]=(ba[i-1]*4)%M;
    ll n,m;
    set<ll> a;
    char s[700000];
    scanf("%I64d %I64d",&n,&m);
    for(ll i=0;i<n;i++)
    {
        scanf("%s",s);
        ll sum=0,l=strlen(s);
        for(ll j=0;j<l;j++,sum%=M)
            sum+=(s[j]-'a'+1)*ba[j];
        a.insert(sum);

    }
    for(ll i=0;i<m;i++)
    {
        scanf("%s",s);
        ll sum=0,l=strlen(s);
        for(ll j=0;j<l;j++,sum>M?sum%=M:0)
            sum+=(s[j]-'a'+1)*ba[j];
        ll ok=0;
        for(ll j=0;j<l&&!ok;j++)
        {
            for(char c='a';c<='c'&&!ok;c++)
            {
                if(s[j]!=c)
                {
                    if(a.find(((sum+(c-s[j])*ba[j])%M+M)%M)!=a.end())
                        ok=1;
                }
            }
        }
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}