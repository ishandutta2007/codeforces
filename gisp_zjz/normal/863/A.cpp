#include<bits/stdc++.h>
#define maxn 23040

using namespace std;
int n,a[10],c;

int main()
{
    scanf("%d",&n);
    while (n&&n%10==0) n/=10;
    while (n) a[c++]=n%10,n/=10;
    for (int i=0;i<c-1;i++) if (a[i]!=a[c-1-i]) {printf("NO\n");return 0;}
    puts("YES");
}