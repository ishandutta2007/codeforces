#include<bits/stdc++.h>
#define maxn 50500
#define M 10000
using namespace std;
int a[maxn],n,b[maxn],s,cnt[maxn],d[maxn],p;
map <int,int> f;

int main()
{
    cin>>n;for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for (int j=10000;j>1;j--) if (a[i]/j/j*j*j==a[i]) {a[i]/=(j*j);break;}
        if (f.find(a[i])==f.end()) f[a[i]]=++p;
    }
    for (int i=0;i<n;i++) b[i]=f[a[i]];
    for (int i=0;i<n;i++)
    {
        for (int j=1;j<=p;j++) cnt[j]=0;s=0;
        for (int j=i;j<n;j++){
            if (a[j]&&!cnt[b[j]]) s++;
            cnt[b[j]]++;
            d[max(1,s)]++;
        }
    }
    for (int i=1;i<=n;i++) cout << d[i] <<' ';
    cout << endl;
    return 0;
}