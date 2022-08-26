#include<bits/stdc++.h>
#define maxn 1500000

using namespace std;
int f[maxn],cnt,x[maxn],y[maxn],n,m,k,r,a[maxn],l;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) f[a[i]]=true;
    while (a[n]>r){
        do{
            for (int i=l+2;i<=a[n]+1;i++) x[cnt]=l+1,y[cnt++]=i;
            l++; r++;
        }while (!f[r]);
        n--;
    }
    cout << cnt << endl;
    for (int i=0;i<cnt;i++) cout << x[i] << ' ' << y[i] << endl;
    return 0;
}