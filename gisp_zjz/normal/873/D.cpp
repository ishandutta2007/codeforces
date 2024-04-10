#include<bits/stdc++.h>
#define maxn 200025
#define eps 1e-6

using namespace std;

int n,m,k,a[maxn];

void f(int l,int r)
{
    int mid=(l+r)/2;
    if (k) {swap(a[mid-1],a[mid]);k--;}
    if (mid-l>1) f(l,mid);
    if (r-mid>1) f(mid,r);
}

int main()
{
    scanf("%d%d",&n,&m);
    if (m%2==0) {printf("-1\n");return 0;}
    k=(m-1)/2;
    if (k>=n) {printf("-1\n");return 0;}
    for (int i=0;i<n;i++) a[i]=i+1;
    f(0,n);
    for (int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");
    return 0;
}