#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=3e6+13;
typedef pair<int,int> pi;
int n,m,a[maxn],d[maxn],tot,r;
pi b[maxn];
int main(){
    scanf("%d",&n);
    if (n<=2) {puts("1");return 0;}
    m=2;
    while ((1<<(m+1))-1<=n) ++m;
    r=1<<m;
    for (int i=1;i<=3;i++) d[i]=a[i]=-1;
    for (int i=4;i<r*2;i++){
        if (i%4==1) d[i]=0,a[i]=0;
        else if (i%4==2) d[i]=0,a[i]=1;
        else if (d[i/2]==-1) d[i]=-1;
        else d[i]=d[i/2]+1;
    }
    for (int i=4;i<r*2;i++) if (d[i]!=-1){
        b[++tot]=(pi){d[i],i};
    }
    sort(b+1,b+tot+1);
    for (int i=1;i<=tot;i++){
        int x=b[i].S;
        if (d[x]!=0){
            a[x]=(a[x/2]^1)^a[x^1];
        }
    }
    int ans=0;
    for (int i=r+1;i<r*2-1;i++) ans+=a[i];
    if (ans+r-1==n||ans+r==n) puts("1"); else puts("0");
}