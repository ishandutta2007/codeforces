#include<bits/stdc++.h>
#define maxn 200002

using namespace std;
int a[maxn],p[maxn],f[maxn],n;

int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    for (int i=n;i>=1;i--){
        for (int j=(p[i]-1)%i+1;j<=n;j+=i)
            if (j!=p[i]&&a[j]>i&&!f[a[j]]) f[i]=true;
    }
    for (int i=1;i<=n;i++)
        if (f[a[i]]) printf("A"); else printf("B");
    puts("");
    return 0;
}