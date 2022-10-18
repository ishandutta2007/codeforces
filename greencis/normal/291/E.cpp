#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

int n,m,ans,p,tlen;
string s[100105];
vector<int> g[100105];
char t[300105];
int aut[300105][26],pi[300105];

void dfs(int v) {
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        for (int j = 0; j < s[to].size(); ++j) {
            pi[n] = aut[pi[n-1]][s[to][j] - 97];
            if (pi[n++] == tlen) ++ans;
        }
        dfs(to);
        n -= s[to].size();
    }
}

int main()
{
    scanf("%d",&m);
    for (int i = 2; i <= m; ++i) {
        scanf("%d%s",&p,t);
        g[p].push_back(i);
        s[i] = t;
    }
    scanf("%s",t);
    tlen = n = strlen(t);
    t[n++] = '#';
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && t[j] != t[i])
            j = pi[j-1];
        if (t[i] == t[j]) ++j;
        pi[i] = j;
    }
    for (int i = 0; i < n; ++i)
        for (int c = 0; c < 26; ++c)
            if (i > 0 && c != t[i] - 97) aut[i][c] = aut[pi[i-1]][c];
            else aut[i][c] = i + (c == t[i] - 97);
    dfs(1);
    printf("%d",ans);
    return 0;
}