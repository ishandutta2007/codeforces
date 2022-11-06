#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define mod 998244353
using namespace std;
char s[N];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    if(s[1]==s[n])
    {
        int l=2,r=n-1;
        while(s[l]==s[l-1]) l++;
        while(s[r]==s[r+1]) r--;
        printf("%lld\n",1ll*(l)*(n-r+1)%mod);
    }
    else
    {
        int l=2,r=n-1;
        while(s[l]==s[l-1]) l++;
        while(s[r]==s[r+1]) r--;
        printf("%d\n",l+n-r);
    }
    return 0;
}