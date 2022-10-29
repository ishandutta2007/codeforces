#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int N = 102;
int n;
char s[N];
struct node{
    int v[26];
    int sz(){
        int sum = 0;
        for (int i = 0; i < 26; i ++)
            sum += v[i];
        return sum;
    }
}o;
bool operator<(node a, node b) {
    for (int i = 0; i < 26; i ++)
        if (a.v[i] != b.v[i]) return a.v[i] < b.v[i];
    return 0;
}
map<node, int> f;
vector<int> work(int n) {
    printf("? %d %d\n", 1, n);
    fflush(stdout);
    for (int i = 1; i <= (n + 1) * n / 2; i ++) {
        scanf("%s", s);
        int len = strlen(s);
        node tmp = o;
        for (int j = 0; j < len ; j ++)
            tmp.v[s[j] - 'a'] ++;
        f[tmp] ++;
    }
    if (n != 1) {
        printf("? %d %d\n", 2, n);
        fflush(stdout);
        for (int i = 1; i <= (n - 1) * n / 2; i++) {
            scanf("%s", s);
            int len = strlen(s);
            node tmp = o;
            for (int j = 0; j < len; j++)
                tmp.v[s[j] - 'a']++;
            f[tmp]--;
        }
    }
    vector<int>d;
    vector<node>dd;
    for (auto u:f)
        if (u.second > 0) {
            dd.push_back(u.first);
        }
    sort(dd.begin(), dd.end(), [](node a, node b) {
        return a.sz() < b.sz();
    });
    for (auto u:dd) {
        for (auto v:d)
            u.v[v] --;
        for (int i = 0; i < 26; i ++)
            if (u.v[i])
                d.push_back(i);
    }
    return d;
}
int main() {
    scanf("%d", &n);
    vector<int>d = work(n);
    printf("! ");
    for (auto u:d)
        printf("%c", u + 'a');
    return 0;
}