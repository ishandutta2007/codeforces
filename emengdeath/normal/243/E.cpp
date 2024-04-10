#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
namespace PQ_tree{//dfsBelNumCalc
    const int MAXN = 5005;
    bool Q[MAXN];
    vector<int> E[MAXN];
    int Num[MAXN][3], Bel[MAXN], Order[MAXN], cnt, N, tot, root;
    void init(int n){
        while (tot) {
            E[tot --].clear();
        }
        root = tot = n + 1;
        N = n;
        for (int i = 1; i <= N ; i ++) E[tot].push_back(i);
    }
    void dfs(int cur, char*s) {
        Num[cur][0] = Num[cur][1] = Num[cur][2] = 0;
        if (cur <= N) {
            Bel[cur] = (s[cur] == '1');
            Num[cur][Bel[cur]] ++;
            return;
        }
        bool f0 = 1, f1 = 1;
        for (auto u:E[cur]){
            dfs(u, s);
            Num[cur][Bel[u]] ++;
            if (Bel[u]) f0 = 0;
            if (Bel[u] != 1) f1 = 0;
        }
        if (f0) Bel[cur] = 0;
        else
            Bel[cur] = 1 + (!f1);
    }
    bool Putl(int cur, vector<int> &E1)
    {
        if (Num[cur][2] > 1) return 0;
        if (Q[cur]) {
            int x = E[cur][0];
            if (Bel[x] != 1 && Num[cur][1] || Bel[x] != 2 && !Num[cur][1])
                reverse(E[cur].begin(), E[cur].end());
            vector<int>::iterator Fr = E[cur].begin();
            for (int i = 1; i <= Num[cur][1]; i ++)
            {
                if (Bel[*Fr] != 1) return 0;
                E1.push_back(*Fr);
                Fr ++;
            }
            bool Flag = 0;
            for (;Fr != E[cur].end(); Fr ++)
            {
                if (!Flag && Num[cur][2] && Bel[*Fr] != 2) return 0;
                if (Bel[*Fr] == 2) {
                    Flag = 1;
                    if (!Putl(*Fr, E1)) return 0;
                } else
                    E1.push_back(*Fr);
            }
            return 1;
        }
        if (Num[cur][1])
        {
            int t1 = ++tot;
            Q[t1] = 0;
            for (auto u:E[cur])
                if (Bel[u] == 1) E[t1].push_back(u);
            if (E[t1].size() == 1) t1 = E[t1][0];
            E1.push_back(t1);
        }
        for (auto u:E[cur])
            if (Bel[u] == 2 && !Putl(u, E1)) return 0;
        if (Num[cur][0])
        {
            int t2 = ++tot;
            Q[t2] = 0;
            for (auto u:E[cur])
                if (!Bel[u]) E[t2].push_back(u);
            if (E[t2].size() == 1) t2 = E[t2][0];
            E1.push_back(t2);
        }
        return 1;
    }
    bool Putr(int cur, vector<int> &E1) {
        int tmp = E1.size();
        if (Putl(cur, E1)) {
            reverse(E1.begin() + tmp, E1.end());
            return 1;
        }
        return 0;
    }
    bool calc(int cur){
        if (cur <= N) return 1;
        if (Num[cur][2] > 2) return 0;
        if (Num[cur][1] + Num[cur][2] == 1)
        {
            for (auto u:E[cur])
                if (Bel[u]) return calc(u);
        }
        vector<int>Tmp;
        Tmp.clear();
        if (Q[cur]) {
            bool End = 0, One = 0;
            for (auto u:E[cur])
            {
                if (End && Bel[u])return 0;
                if (One && !Bel[u]) End = 1;
                if (Bel[u] == 2)
                {
                    if (!One)
                    {
                        if (!Putr(u, Tmp)) return 0;
                    } else
                        if (!Putl(u, Tmp)) return 0;
                } else
                    Tmp.push_back(u);
                if (Bel[u]) One = 1;
            }
            E[cur] = Tmp;
            return 1;
        }
        int t1 = ++tot; Q[t1] = 1;
        for (auto u:E[cur])
            if (Bel[u] == 2) {
                if (!Putr(u, E[t1])) return 0;
                break;
            }
        if (Num[cur][1]) {
            int t2 = ++tot;
            Q[t2] = 0;
            for (auto u:E[cur])
                if (Bel[u] == 1) E[t2].push_back(u);
            if (E[t2].size() == 1)t2 = E[t2][0];
            E[t1].push_back(t2);
        }
        int F1 = 0;
        for (auto u:E[cur])
            if (Bel[u] == 2) {
                if (!F1) F1 = 1;
                else{
                    if (!Putl(u, E[t1])) return 0;
                    break;
                }
            }
        if (E[t1].size() == 1) t1 = E[t1][0];
        Tmp.push_back(t1);
        for (auto u:E[cur])
            if (!Bel[u]) Tmp.push_back(u);
        E[cur] = Tmp;
        return 1;
    }
    bool add_constrain(char*s){
        dfs(root, s);
        return calc(root);
    }
    void Get_Order(int cur) {
        if (cur <= N) {
            Order[++cnt] = cur;
            return;
        }
        for (auto u:E[cur])
            Get_Order(u);
    }
    void Get_All_Order()
    {
        cnt = 0;
        Get_Order(root);
    }
}

int n;
char s[1000][1000];
int main() {
    scanf("%d", &n);
    PQ_tree::init(n);
    for (int i = 1; i <= n ; i  ++){
        scanf("%s", s[i] + 1);
        if (!PQ_tree::add_constrain(s[i])){
            printf("NO\n");
            return 0;
        }
    }
    PQ_tree::Get_All_Order();
    printf("YES\n");
    for (int i = 1; i <= n ; i ++) {
        for (int j = 1; j <= n; j++)
            printf("%c", s[i][PQ_tree::Order[j]]);
        printf("\n");
    }
    return 0;
}