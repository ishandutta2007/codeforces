#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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


int n, x;
vector <int> ans;
stack <int> s[N];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        s[x].push(i);
    }

    int now = 0;
    for (int i = 1; i <= n; i++){
        if (s[now].empty()){
            while (now >= 0 && s[now].empty())
                now -= 3;
            if (now < 0){
                puts("Impossible");
                return 0;
            }
        }
        ans.push_back(s[now].top());
        s[now].pop();
        now++;
    }
    puts("Possible");
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
}