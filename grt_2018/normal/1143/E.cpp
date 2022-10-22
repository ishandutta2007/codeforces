#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*100*1000+10;
int n,m,q;
int a[MAXN];
int b[MAXN];
int nextt[MAXN];
int gdzie[MAXN][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0; i<n;i++) {
        cin>>a[i];
    }
    for(int i=0; i<n;i++) {
        b[a[i]] = i+1;
    }
    for(int i=0; i<m;i++) {
        cin>>a[i];
        a[i] = b[a[i]];
    }
    for(int i=0; i<=n;i++) nextt[i] = m+1;
    for(int i=m-1; i>=0;i--) {
        if(a[i]==n) gdzie[i][0] = nextt[1];
        else gdzie[i][0] = nextt[a[i]+1];
        nextt[a[i]] = i;
    }
    for(int j=1; j<20; j++) {
        for(int i=0; i<m;i++) {
            if(gdzie[i][j-1]==m+1) gdzie[i][j] = m+1;
            else gdzie[i][j] = gdzie[gdzie[i][j-1]][j-1];
        }
    }
    for(int i=0; i<m;i++) {
        int tmp = n-1,ile=0,pos=i;
        while(tmp>0) {
            if(tmp&1) {
                if(pos<m+1)
                    pos = gdzie[pos][ile];
            }
            tmp/=2;
            ile++;
        }
        a[i] = pos;
    }
    for(int i=0; i<m;i++) gdzie[i][0] = a[i];
    for(int j=1; j<20; j++) {
        for(int i=0; i<m;i++) {
            if(i+(1<<(j-1))>=m) gdzie[i][j] = gdzie[i][j-1];
            else gdzie[i][j] = min(gdzie[i][j-1],gdzie[i+(1<<(j-1))][j-1]);
        }
    }
    for(int l,r,i=0; i<q;i++) {
        cin>>l>>r;
        int b = (31-__builtin_clz(r-l+1));
        int ans = min(gdzie[l-1][b],gdzie[r-(1<<b)][b]);
        if(ans<r) cout<<"1";
        else cout<<"0";
    }
    return 0;
}