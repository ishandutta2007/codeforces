#include<bits/stdc++.h>
#define maxn 235000

using namespace std;
char s[maxn];
int n,ans,d,l;

int main()
{
    scanf("%s",s); n=strlen(s); ans=n;
    for (char c='a';c<='z';c++)
    {
        l=-1; d=0;
        for (int i=0;i<n;i++)
            if (s[i]==c) d=max(d,i-l),l=i;
        d=max(d,n-l);
        ans=min(ans,d);
    }
    cout << ans << endl;
}