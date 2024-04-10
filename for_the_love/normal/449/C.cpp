#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const DB eps = 1e-6;


int v[N], a[N], used[N], n;

bool cmp(int i, int j){return v[i] < v[j];}
vector <PI> ans;
int main(){
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) if (!v[i])
    for (int j = 1; j * i <= n; j++) v[i * j]++;

    for (int i = n; i >= 2; i--)if (v[i] == 1){
        int cnt = 0;
        for (int j = 1; j * i <= n; j++)
        if (!used[i * j]) a[++cnt] = i * j;
        sort(a + 1, a + cnt + 1, cmp);
        for (int j = 1; j + 1 <= cnt; j += 2){
            used[a[j]] = used[a[j + 1]] = 1;
            ans.PB(MP(a[j], a[j + 1]));
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);

}