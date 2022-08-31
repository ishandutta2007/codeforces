#include<bits/stdc++.h>
#define maxn 230400

using namespace std;
char s[12030];

int main()
{
    int n;scanf("%d",&n);
    scanf("%s",s); int ans=n;
    for (int i=0;i<n-1;i++)
        if (s[i]!=s[i+1]) i++,ans--;
    cout << ans << endl;
}