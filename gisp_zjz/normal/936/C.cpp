#include<bits/stdc++.h>

using namespace std;
char s[2555],t[2555];
int n,ans[2555*3],o;

int main()
{
    scanf("%d",&n);
    scanf("%s",s); scanf("%s",t); o=0;
    for (int i=n-1;i>=0;i--)
    {
        int j=n-1-i;
        while (j<n&&s[j]!=t[i]) j++;
        if (j==n){printf("-1\n");return 0;}
        ans[o++]=n; ans[o++]=j; ans[o++]=1;
        reverse(s+j,s+n);reverse(s,s+n);reverse(s+1,s+n);
    }
    cout << o << endl;
    for (int i=0;i<o;i++) printf("%d ",ans[i]); printf("\n");
}