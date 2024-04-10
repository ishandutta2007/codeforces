#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2000005;
const int maxm = 6000005;

int n,k;
int rev(int x){
    return n-x+1;   
}
bool f[1005][1005],a[1005][1005];
char s[1005];
int id1(int x,int y){
    if (x<1||x>n||y<1||y>n) return -1;
    return ((x-1)*n+y)*2+1;
}
int id2(int x,int y){
    if (x<1||x>n||y<1||y>n) return -1;
    return ((x-1)*n+y)*2+2;
}
bool check(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]==0&&f[i][j]==0) return 0;
    return 1;
}
int id[1005][1005],cnt[2005],b[2005][1005];
vector<int> H[2005];
void solve() {
    cin >> n >> k; k--;
    for (int i=1;i<=n;i++){
        cin >> s+1;
        for (int j=1;j<=n;j++) f[i][j]=(s[j]=='1');
    }
    for (int i=2;i<=n*2;i++){
        cnt[i]=0; H[i].clear();
        H[i].pb(0);
        for (int j=0;j<=n;j++) b[i][j]=0;
    }
    for (int i=1;i<=n;i++) reverse(f[i]+1,f[i]+n+1);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++){
        if (i+j<=k||rev(i)+rev(j)<=k){
            a[i][j]=1;
            continue;
        }
        cnt[i+j]++;
        id[i][j]=cnt[i+j];
        if (!f[i][j]) H[i+j].pb(id[i][j]);
    }
    int now[2005];
    for (int r=k;r;r--){
        for (int i=k+1;i<=2*n+1-k;i++) now[i]=max(H[i].back(),r);
        for (int i=k+2;i<=n+1;i++) now[i]=max(now[i],now[i-1]);
        for (int i=n+2;i<=2*n+1-k;i++) now[i]=max(now[i],now[i-1]-1);
        for (int i=2*n-k;i>=n+1;i--) now[i]=max(now[i],now[i+1]);
        for (int i=n;i>=k+1;i--) now[i]=max(now[i],now[i+1]-1);
        for (int i=k+1;i<=2*n+1-k;i++){
            b[i][now[i]]=1;
            if (now[i]==H[i].back()) H[i].pop_back();
        }
    }
    for (int i=k+1;i<=2*n+1-k;i++) if (H[i].back()>0){
        cout << "NO" << endl;
        return;
    }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++){
        if (i+j<=k) continue;
        if (rev(i)+rev(j)<=k) continue;
        if (b[i+j][id[i][j]]) a[i][j]=1; else a[i][j]=0;
    }
    cout << "YES" << endl;
    for (int i=1;i<=n;i++){
        for (int j=n;j;j--) cout << a[i][j];
        cout << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}