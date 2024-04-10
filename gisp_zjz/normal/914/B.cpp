#include<bits/stdc++.h>
#define maxn 2030400

using namespace std;

int n,a[maxn],cnt[maxn],r;
bool f;

int main()
{
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<n;i++)
    {
        scanf("%d",&r); cnt[r]++;
    }
    f=true;
    for (int i=1;i<=100000;i++) if (cnt[i]%2==1) f=false;
    if (f) printf("Agasa\n"); else printf("Conan\n");
    return 0;
}