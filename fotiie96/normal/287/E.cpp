#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define clr(a) memset(a,0,sizeof(a))
int n,v[1010000],neg[1010000],s[1010000],top,t,x;
int main() {
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&v[i]);
    scanf("%d",&t);
    rep(i,0,t) scanf("%d",&x),neg[x]=1;
    top=0;
    for (int i=n;i>=1;i--) {
        if (top>0&&!neg[i]&&v[i]==v[s[top]]) {
            v[s[top]]*=-1;
            --top;
        } else s[++top]=i;
    }
    if (top!=0) puts("NO");
    else {
        puts("YES");
        rep(i,1,n+1) printf("%d ",v[i]); 
    }
}