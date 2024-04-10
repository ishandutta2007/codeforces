#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;
struct node{
    int id, sum;
    char c;
}a[N], b[N];
string s[N];
bool bz[1000];
int n, tot;
vector<pair<int, int> > f, g;
bool cmp(const node & a ,const node &b)
{
    return a.sum < b.sum || (a.sum == b.sum && a.c < b.c);
}
int main()
{
    bz['a'] = 1;
    bz['e'] = 1;
    bz['i'] =1 ;
    bz['o'] = 1;
    bz['u'] = 1;
    scanf("%d", &n);
    for (int i = 1;i <= n ; i ++) {
        cin >> s[i];
        a[i].id = i;
        for (auto u:s[i])
            if (bz[(int)u])
                a[i].c = u, a[i].sum ++;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n ; i++)
        if (a[i].c == a[i - 1].c && a[i].sum == a[i - 1].sum)
        {
            f.push_back(make_pair(a[i].id, a[i - 1].id));
            a[i].c = a[i - 1].c = 0;
        }
    for (int i = 1; i <= n ; i ++)
        if (a[i].c) b[++ tot] = a[i];
    for (int i = 1; i <= tot ; i ++)
        if (b[i - 1].c && b[i - 1].sum == b[i].sum){
            b[i].c = b[i - 1].c = 0;
            g.push_back(make_pair(b[i].id, b[i - 1].id));
        }
    while (f.size() > g.size())
    {
        g.push_back(f[f.size() - 1]);
        f.pop_back();
    }
    int ans = f.size();
    printf("%d\n", ans);
    for (int i = 0; i < ans; i ++){
        cout << s[g[i].first] << ' ' << s[f[i].first] << endl;
        cout << s[g[i].second] << ' ' << s[f[i].second] << endl;
    }
    return 0;
}