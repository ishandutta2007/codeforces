#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int n, m, x[N], v[N], ans[N];

char op[N];
vector <int> res;

set <int> S;
queue <int> Q;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        scanf(" %c %d", &op[i], &x[i]);
        if (!v[x[i]]){
            if (op[i] == '-'){
                v[x[i]] = 1;
            }else{
                v[x[i]] = 2;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (v[i] == 1) cnt++;



    if (cnt){
        for (int i = 1; i <= n; i++) if (v[i] == 2) ans[i] = 1;
    }else for (int i = 1; i <= n; i++)
        if (v[i] == 2) S.insert(i);


    for (int i = 0; i < m; i++){
        if (op[i] == '-'){
            if (cnt > 1) ans[x[i]] = 1;
            if (!ans[x[i]]) S.insert(x[i]);
            cnt--;
        }
        if (op[i] == '+'){
            S.erase(x[i]);
            cnt++;
            for (set<int>:: iterator it = S.begin(); it != S.end(); it++){
                ans[*it] = 1;
                Q.push(*it);
            }
            while (!Q.empty()){
                S.erase(Q.front());
                Q.pop();
            }

        }
    }

    for (int i = 1; i <= n; i++)
    if (!ans[i]) res.PB(i); //printf("%d ", i);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
}