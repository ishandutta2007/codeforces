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
char s[1005];
bool f[1005],g[1005];
int _,n,m;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> m >> s;
        m=min(m,n);
        f[0]=f[n+1]=0;
        for (int i=1;i<=n;i++) f[i]=s[i-1]=='1';
        while (m--){
            for (int i=1;i<=n;i++) g[i]=f[i]|(f[i-1]^f[i+1]);
            for (int i=1;i<=n;i++) f[i]=g[i];
        }
        for (int i=1;i<=n;i++) printf("%d",f[i]);puts("");
    }
    return 0;
}