#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
int n,a[maxn],d[maxn],x,t,l,r,mid,L,R;
ll s,ss;

bool cmp(int x,int y){return y<x;}

int f(int x) {
    if (!(x>=0&&x<n)) return (x<0)?-1:1;
    for (int i=1;i<n;i++) a[i]=d[i]; a[n]=x;
    sort(a+1,a+1+n,cmp); s=ss=0;
    int j=n;
    for (int i=1;i<=n;i++) {
        s+=a[i];
        while (j>i&&a[j]<=i) ss+=a[j],j--;
        if (j<i) ss-=a[i];
        if (s>(1ll*i*(i-1))+ss+1ll*(max(0,j-i))*i) return (a[i]<=x)?1:-1;
    }
    return 0;
}

int main(){
    cin >> n; n++;
    for (int i=1;i<n;i++) scanf("%d",&d[i]);
    for (int i=1;i<n;i++) x=(x+d[i])&1;
    l=0; r=n/2; L=-1;
    while (l<=r){
        mid=(l+r)/2;
        int flag=f(mid*2+x);
        if (flag==-1) l=mid+1; else r=mid-1;
        if (!flag) L=mid;
    }
    if (L==-1) {puts("-1");return 0;}
    l=L; r=n/2; R=-1;
    while (l<=r){
        mid=(l+r)/2;
        if (!f(mid*2+x)) R=mid,l=mid+1; else r=mid-1;
    }
    if (R==-1) {puts("-1");return 0;}
    for (int i=L;i<=R;i++) printf("%d ",i*2+x); cout << endl;
    return 0;
}