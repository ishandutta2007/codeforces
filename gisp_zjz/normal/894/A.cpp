#include<bits/stdc++.h>
using namespace std;
char s[400];
int n,ans;

int main()
{
    scanf("%s",s);
    n=strlen(s);
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            for (int k=j+1;k<n;k++)
                if (s[i]=='Q'&&s[j]=='A'&&s[k]=='Q') ans++;
    cout<<ans<<endl;
}