#include<bits/stdc++.h>
#define maxn 203400

using namespace std;
typedef long long ll;
int a[maxn],l,r,n;
char s[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%s",s);
    l=-1000000000;
    r=1000000000;
    for (int i=4;i<n;i++)
    {
        if (s[i]==s[i-1]) continue;
        if (s[i]=='1') for (int j=0;j<5;j++) l=max(l,a[i-j]+1);
        else for (int j=0;j<5;j++) r=min(r,a[i-j]-1);
    }
    cout << l << ' ' << r << endl;
    return 0;
}