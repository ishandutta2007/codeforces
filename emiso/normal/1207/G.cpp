#include <bits/stdc++.h>

using namespace std;

#define MN 400100
#define ALP 26

int C(char c) { return c - 'a'; }

struct jonson {
    jonson* child[ALP];
    vector<pair<int, int>> queries;

    jonson() {
        for(int i = 0; i < ALP; i++)
            child[i] = NULL;
    }
} *wilson;

int n, m, ans[MN], final_ans[MN];
jonson* rev[MN];
char s[MN];
set<string> klebin;

struct aho {
    int parent[MN], suffix[MN], transition[MN][ALP], super[MN];
    char from[MN];
    int id[MN], cnt, built;
    long long ending[MN], lazy[MN];

    int new_node(int _parent = 0, char _from = ' ') {
        parent[cnt] = _parent; from[cnt] = _from; id[cnt] = -1;
        suffix[cnt] = super[cnt] = ending[cnt] = lazy[cnt] = 0;
        for(int i = 0; i < ALP; i++) transition[cnt][i] = 0;
        return cnt++;
    }

    aho() {
        cnt = built = 0;
        new_node();
    }

    int add_word(string &word, int _id = 0) {
        int node = 0;
        for(int i = 0; i < word.size(); i++) {
            int nxt = C(word[i]);
            if(!transition[node][nxt]) transition[node][nxt] = new_node(node, word[i]);
            node = transition[node][nxt];
        }
        ending[node]++;
        if(id[node] == -1) id[node] = _id;
        return id[node];
    }

    void build() {
        built = 1;
        queue<int> q;
        for(int i = 0; i < ALP; i++)
            if(transition[0][i]) q.push(transition[0][i]);

        while(!q.empty()) {
            int v = q.front(); q.pop();
            if(parent[v]) suffix[v] = transition[suffix[parent[v]]][C(from[v])];

            if(id[v] != -1) super[v] = v;
            else super[v] = super[suffix[v]];

            ending[v] += ending[suffix[v]];
            for(int i = 0; i < ALP; i++) {
                if(!transition[v][i]) transition[v][i] = transition[suffix[v]][i];
                else q.push(transition[v][i]);
            }
        }
    }

    void search_text(jonson* node, int *ans, int where = 0) {
        if(!built) build();
        int prefix;

        for(int i = 0; i < ALP; i++) {
            jonson* nxt = node->child[i];
            if(!nxt) continue;

            prefix = transition[where][i];
            for(int u = super[prefix]; u; u = super[suffix[u]])
                ans[id[u]]++;

            for(auto x : nxt->queries) {
                final_ans[x.first] = ans[x.second];
            }

            search_text(nxt, ans, prefix);
            for(int u = super[prefix]; u; u = super[suffix[u]])
                ans[id[u]]--;
        }
    }
} dict;

int main() {
    wilson = new jonson();
    rev[0] = wilson;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int t, j; char c;
        scanf("%d", &t);
        if(t == 1) {
            scanf(" %c", &c);
            j = 0;
        } else if(t == 2) {
            scanf("%d %c", &j, &c);
        } else assert(false);

        jonson* tmp = rev[j];
        if(tmp->child[C(c)] == NULL)
            tmp->child[C(c)] = new jonson();

        rev[i] = tmp->child[C(c)];
    }

    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        int x; string str;
        scanf("%d %s", &x, s);
        str = s;

        int id = dict.add_word(str, klebin.size());
        rev[x]->queries.emplace_back(i, id);
        klebin.insert(str);
    }

    dict.search_text(wilson, ans);
    for(int i = 1; i <= m; i++) {
        printf("%d\n", final_ans[i]);
    }

    return 0;
}