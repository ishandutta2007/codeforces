#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5001;
int n,q,cnt,ans;
int painted[MAXN];
int p[MAXN];
int workers[MAXN][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=q;i++) {
        cin>>workers[i][0]>>workers[i][1];
        for(int j=workers[i][0]; j<=workers[i][1]; j++)
            painted[j]++;
    }
    for(int i=1; i<=q;i++) {
        cnt = 0;
        for(int j=workers[i][0]; j<=workers[i][1]; j++)
            painted[j]--;
        for(int j=1; j<=n;j++) {
            p[j] = p[j-1] + (painted[j]==1);
            cnt+=(painted[j]>0);
        }
        for(int j=1; j<=q;j++) {
            if(i==j) continue;
            ans = max(ans,cnt - (p[workers[j][1]] - p[workers[j][0]-1]));
        }
        for(int j=workers[i][0]; j<=workers[i][1]; j++)
            painted[j]++;
    }
    cout<<ans;
    return 0;
}