#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int _,n,a[maxn],b[maxn],c[maxn];
void solve(){
    int p=n; b[n+1]=-1;
    for (int i=n;i;i--){
        while (p>0&&b[p]==b[p+1]) c[b[p]]++,p--;
        if (p>0&&b[p]==a[i]) {p--;continue;}
        if (c[a[i]]) {c[a[i]]--;continue;}
        puts("NO"); return;
    }
    puts("YES");
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        for (int i=1;i<=n;i++) c[i]=0;
        solve();
    }
}