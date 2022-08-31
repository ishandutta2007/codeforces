#include<bits/stdc++.h>
#define N 103040
#define F first
#define S second
#define M 1000000009

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll n,k,r,d,ans,a,b,c,p,o;
char s[N];

ll pow_(ll x,ll y)
{
    ll rt=1; while (y){if (y&1) rt=rt*x%M; x=x*x%M; y/=2;} return rt;
}

int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&k);
    b=b*pow_(a,M-2)%M; o=pow_(b,k);
    scanf("%s",s);
    for (int i=0;i<k;i++)
    {
        if (n-i<0) continue;
        r=(n-i)/k;
        if (o==1){
            if (s[i]=='+') (ans+=pow_(b,i)*(r+1))%=M;
            else (ans-=pow_(b,i)*(r+1))%=M;
        }
        else {
            if (s[i]=='+') (ans+=pow_(b,i)*(pow_(o,r+1)-1))%=M;
            else (ans-=pow_(b,i)*(pow_(o,r+1)-1))%=M;
        }
    }
    ans=ans*pow_(a,n)%M;
    if (o!=1) ans=ans*pow_(o-1,M-2)%M;
    cout << (ans+M)%M << endl;
}