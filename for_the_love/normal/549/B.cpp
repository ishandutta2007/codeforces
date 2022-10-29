#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n;
char s[105][105];
int a[105];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector <int> ans;
    while (1){
        int flag = 0, p ;
        for (int i = 0; i < n; i++)
        if (!a[i]){
            ans.PB(i);
            p = i;
            flag = 1;
            break;
        }
        if (!flag) break;
        for (int i = 0; i < n; i++)
            a[i] -= s[p][i] - '0';
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ",ans[i] + 1); puts("");
}