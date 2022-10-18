#include <cstdio>
#include <stack>
#include <cstring>

int n, k;
char seq[300000];
int pair[300000], vis[300000];
std::stack <int> stk;

int main() {
    scanf("%d %d %s", &n, &k, &seq);
    for (int i=0;i<n;++i) {
        if (seq[i]=='(') {
            stk.push(i);
        } if (seq[i]==')') {
            int u=stk.top(); pair[u]=i; pair[i]=u; stk.pop();
        }
    }std::memset(vis, 0, sizeof(vis));
    k=n-k;
    for (int i=0;i<n&&k>0;++i) {
        if (!vis[i]) {
            vis[i]=vis[pair[i]]=1;
            k-=2;
        }
    }for (int i=0;i<n;++i) if (!vis[i]) printf("%c", seq[i]);
    return 0;
}