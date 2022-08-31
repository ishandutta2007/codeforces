#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=234556;
int _,ans[maxn],n,a[maxn];
char s[maxn];
bool check(int x){
    int l,r,v;
    l=-1; v=-1;
    for (int i=0;i<n;i++) if (a[i]<x) {
        if (a[i]<v) return 0;
        v=a[i]; l=i;
    }
    r=n; v=10;
    for (int i=n-1;i>=0;i--) if (a[i]>x){
        if (a[i]>v) return 0;
        v=a[i]; r=i;
    }
    for (int i=r+1;i<=l-1;i++) if (a[i]==x) return 0;
    for (int i=0;i<r;i++) if (a[i]==x) ans[i]=2;
    for (int i=l+1;i<n;i++) if (a[i]==x) ans[i]=1;
    for (int i=0;i<n;i++) {
        if (a[i]<x) ans[i]=1;
        if (a[i]>x) ans[i]=2;
    }
    return 1;
}
void work(int x){
    for (int i=0;i<n;i++) printf("%d",ans[i]);puts("");
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%s",&n,s);
        for (int i=0;i<n;i++) a[i]=s[i]-'0';
        bool flag=0;
        for (int i=0;i<=9;i++) if (check(i)) {work(i);flag=1;break;}
        if (!flag) puts("-");
    }
    return 0;
}