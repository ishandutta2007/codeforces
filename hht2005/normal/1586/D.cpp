#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main() {
    int n,FL=1,x;
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        printf("?");
        for(int j=2;j<=n;j++)
            printf(" %d",i);
        cout<<" 1"<<endl;
        scanf("%d",&x);
        if(x)FL=i;
    }
    a[n]=FL;
    for(int i=1;i<a[n];i++) {
        printf("? ");
        for(int j=1;j<n;j++)
            printf("%d ",a[n]-i+1);
        cout<<1<<endl;
        scanf("%d",&x);
        a[x]=i;
    }
    for(int i=a[n]+1;i<=n;i++) {
        printf("? ");
        for(int j=1;j<n;j++)
            printf("%d ",1);
        cout<<i-a[n]+1<<endl;
        scanf("%d",&x);
        a[x]=i;
    }
    printf("! ");
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    cout<<endl;
    return 0;
}