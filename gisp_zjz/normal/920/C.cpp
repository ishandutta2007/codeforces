#include<bits/stdc++.h>
#define maxn 200050

using namespace std;

int a[maxn],n,k;
char s[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%s",s); k=0;
    for (int i=0;i<n-1;i++)
    {
        if (s[i]=='0'){
            sort(a+k,a+i+1);
            k=i+1;
        }
    }
    sort(a+k,a+n);
    for (int i=0;i<n;i++) if (a[i]!=i+1){printf("NO\n");return 0;}
    printf("YES\n");
}