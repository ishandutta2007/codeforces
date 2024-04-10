#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long check(string a,string b)
{
    long i,n=a.length(),m=b.length(),cur=0,cnt=0;
    if(n<m) return 0;
    for(i=0;i<n;++i)
    {
        if(a[i]==b[cur]) cur++;
        if(cur==m)
        {
            cur=0;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    io
    long b,d,i,j,f,s,ff,ss,dp[201]={0},k;
    string a,c,temp;
    cin>>b>>d>>a>>c;
    if(b<100)
    {
        for(i=0;i<b;++i)
        temp=temp+a;
        cout<<check(temp,c)/d;
        return 0;
    }
    for(i=1;i<=200;++i)
    {
        temp=temp+a;
        dp[i]=check(temp,c);
    }
    for(i=1;i<=200;++i)
    {
        f=1;
        for(j=i+2;j<=100;j++)
        if(dp[j]-dp[j-1]!=dp[j%i+i*(!(j%i))]-dp[j%i+i*(!(j%i))-1]) {f=0;break;}
        if(f) break;
    }
    cout<<(dp[1]+(dp[i+1]-dp[1])*((b-1)/i)+dp[1+(b-1)%i]-dp[1])/d;
    return 0;
}