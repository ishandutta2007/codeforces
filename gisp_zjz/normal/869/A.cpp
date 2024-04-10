#include<bits/stdc++.h>
#define maxn 2020
#define maxm 5005000
#define eps 1e-9

using namespace std;
typedef long long ll;

int a[maxn],b[maxn],cnt,n;
bool f[maxm];

int main()
{
    scanf("%d",&n);
    memset(f,false,sizeof(f));cnt=0;
    for (int i=0;i<n;i++) {scanf("%d",&a[i]);f[a[i]]=true;}
    for (int i=0;i<n;i++) {scanf("%d",&b[i]);f[b[i]]=true;}
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (f[a[i]^b[j]]) cnt++;
    if (cnt%2) printf("Koyomi\n"); else printf("Karen\n");
    return 0;
}