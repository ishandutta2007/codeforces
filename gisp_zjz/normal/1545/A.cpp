#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int _,n,a[maxn],b[maxn],t[maxn][2];
void solve(){
    scanf("%d",&n);
    memset(t,0,sizeof(t));
    for (int i=1;i<=n;i++){scanf("%d",&a[i]);b[i]=a[i];}
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++){
        t[a[i]][i&1]++;
        t[b[i]][i&1]--;
    }
    bool flag=1;
    for (int i=1;i<=100000;i++)
        if (t[i][0]||t[i][1]) flag=0;
    if (flag) puts("YES"); else puts("NO");
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}