#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int _,n,m,p,q,f,g;
char s[maxn],t[maxn],a[maxn],b[maxn];
int main(){
    cin >> _;
    while (_--){
        cin >> s+1 >> t+1;
        n=strlen(s+1); m=strlen(t+1);
        f=g=p=q=0;
        for (int i=1;i<=n;i++){
            if (s[i]=='B') f^=1; else a[++p]=s[i];
            while (p>=2&&a[p-1]==a[p]) p-=2;
        }
        for (int i=1;i<=m;i++){
            if (t[i]=='B') g^=1; else b[++q]=t[i];
            while (q>=2&&b[q-1]==b[q]) q-=2;
        }
        bool flag=1;
        if (f!=g) flag=0;
        if (p!=q) flag=0;
        for (int i=1;i<=min(p,q);i++) if (a[i]!=b[i]) flag=0;
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}