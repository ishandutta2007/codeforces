#include<bits/stdc++.h>
#define maxn 555555
#define F first
#define S second

using namespace std;
typedef long long ll;
int n,q,D[maxn],cnt[maxn],l[maxn],r[maxn],c[maxn],a[maxn][19],pos;
int rmq(int x,int y){
    int d=D[y-x+1];
    return min(a[x][d],a[y-(1<<d)+1][d]);
}

int main(){
    for (int j=0;j<19;j++)
        for (int i=(1<<j);i<(1<<(j+1));i++) D[i]=j;
    cin >> n >> q;
    for (int i=1;i<=n;i++) {
        scanf("%d",&c[i]); cnt[c[i]]++;
    }
    pos=0;
    for (int i=1;i<=n;i++) if (c[i]) pos=i;
    if (!pos){
        puts("YES");
        for (int i=1;i<=n;i++) printf("%d ",q); printf("\n");
        return 0;
    }
    for (int i=pos-1;i>=1;i--) if (!c[i]){
        if (!cnt[q]) cnt[q]++,c[i]=q;
        else c[i]=c[i+1],cnt[c[i]]++;
    }
    for (int i=pos+1;i<=n;i++) if (!c[i]){
        if (!cnt[q]) cnt[q]++,c[i]=q;
        else c[i]=c[i-1],cnt[c[i]]++;
    }
    if (!cnt[q]){
        puts("NO"); return 0;
    }
    for (int i=1;i<=n;i++) a[i][0]=c[i];
    for (int j=1;j<18;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            a[i][j]=min(a[i][j-1],a[i+(1<<(j-1))][j-1]);
    for (int i=1;i<=q;i++) l[i]=r[i]=-1;
    for (int i=1;i<=n;i++) {
        if (l[c[i]]==-1) l[c[i]]=i;
        r[c[i]]=i;
    }
    for (int i=1;i<=q;i++) if (l[i]!=-1){
        if (rmq(l[i],r[i])<i) {
            puts("NO"); return 0;
        }
    }
    puts("YES");
    for (int i=1;i<=n;i++) printf("%d ",c[i]); printf("\n");
    return 0;
}