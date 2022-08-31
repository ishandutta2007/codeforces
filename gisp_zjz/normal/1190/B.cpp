#include<bits/stdc++.h>
#define maxn 500050
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int a[maxn],n,tot,pos;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    if (n==2&&a[0]==0&&a[1]==0){
        puts("cslnb");return 0;
    }
    if (n==1){
        if (a[0]&1) puts("sjfnb"); else puts("cslnb");
        return 0;
    }
    for (int i=1;i<n;i++) if (a[i]==a[i-1]) pos=i-1,++tot;
    if (tot>1) puts("cslnb");
    else if (tot==1&&pos>0&&a[pos]-1==a[pos-1]) puts("cslnb");
    else if (tot==1&&pos==0&&a[0]==0) puts("cslnb");
    else {
        long long s=0;
        for (int i=0;i<n;i++) s+=a[i];
        s-=1ll*n*(n-1)/2;
        if (s&1) puts("sjfnb"); else puts("cslnb");
    }
    return 0;
}