#include<bits/stdc++.h>
#define maxn 1000050
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
char s[maxn],a[maxn],b[maxn];
int n,m,c[maxn],p,q;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++) c[i]=c[i-1]+(s[i]!='a');
    if (c[n]%2) {puts(":(");return 0;}
    int pos=n;
    while (c[pos]!=c[n]/2) pos--;
    for (int i=1;i<=pos;i++) if (s[i]!='a') a[++p]=s[i];
    for (int i=pos+1;i<=n;i++) if (s[i]=='a') {puts(":(");return 0;} else b[++q]=s[i];
    assert(p==q);
    for (int i=1;i<=p;i++) if (a[i]!=b[i]) {puts(":(");return 0;}
    for (int i=1;i<=pos;i++) printf("%c",s[i]); puts("");
    return 0;
}