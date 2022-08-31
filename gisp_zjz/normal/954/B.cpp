#include<bits/stdc++.h>
#define maxn 230400

using namespace std;
char s[12030];

int n,k;

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    k=n;
    for (int i=2;i<=n/2;i++)
    {
        bool f=true;
        for (int j=0;j<i;j++) if (s[j]!=s[j+i]) f=false;
        if (f) k=n-i+1;
    }
    cout << k << endl;
}