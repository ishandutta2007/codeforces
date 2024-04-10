#include<bits/stdc++.h>
#define maxn 234005
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
char s[maxn],t[maxn];
int n,m,p,q,f,pos;

int main(){
    cin >> n >> m;
    cin >> s;
    cin >> t;
    f=0;
    for (int i=0;i<n;i++) if (s[i]=='*') f=1,pos=i;
    if (!f){
        p=1; if (n!=m) p=0;
        if (p) {
            for (int i=0;i<n;i++) if (s[i]!=t[i]) p=0;
        }
        if (p) puts("YES"); else puts("NO");
    }
    else {
        if (n-1>m) {
            puts("NO"); return 0;
        }
        p=1;
        for (int i=0;i<pos;i++) if (s[i]!=t[i]) p=0;
        for (int i=pos+1;i<n;i++) if (s[i]!=t[m-n+i]) p=0;
        if (p) puts("YES"); else puts("NO");
    }
}