#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int nxt[maxn][19],v[19],d[maxn],b[maxn][19],p[maxn],id[maxn],a[maxn],n,m,q,l,r,last[maxn];

int qry(int l,int r){
    int len=d[r-l+1];
    return min(b[l][len],b[r-(1<<len)+1][len]);
}

int main(){
    cin >> n >> m >> q;
    for (int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
        id[a[i]]=i;
    }
    for (int i=0;i<m;i++){
        cin >> p[i];
        p[i]--;
        p[i]=id[p[i]];
    }
    for (int i=0;i<n;i++) last[i]=m;
    for (int i=m-1;i>=0;i--){
        nxt[i][0]=last[(p[i]+1)%n];
        last[p[i]]=i;
    }
    nxt[m][0]=m;
    for (int i=1;i<19;i++)
        for (int j=0;j<=m;j++)
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
    for (int i=0;i<m;i++){
        int ret=i;
        for (int j=0;j<19;j++) if ((n-1)&(1<<j)) ret=nxt[ret][j];
        b[i][0]=ret;
    }
    for (int i=1;i<19;i++)
        for (int j=0;j+(1<<i)-1<m;j++)
            b[j][i]=min(b[j][i-1],b[j+(1<<(i-1))][i-1]);
    for (int i=2;i<maxn;i++) d[i]=d[i/2]+1;
    while (q--){
        cin >> l >> r;
        l--; r--;
        if (qry(l,r)<=r) printf("1"); else printf("0");
    }
    puts("");
    return 0;
}