#include <bits/stdc++.h>

using namespace std;

#define N 200100
#define ALP_SIZ 27

int get(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    return 26; // "$";
}

int oc;

struct Automaton {
    struct AC_node {
        int fail, wid, endLink, child[ALP_SIZ];
        bool leaf;
    };
    queue<int> q;
    AC_node* no[N];
    int nodes;

    int newnode() {
        no[nodes] = new AC_node();
        no[nodes]->fail = no[nodes]->wid = no[nodes]->endLink = no[nodes]->leaf = 0;
        memset(no[nodes]->child, 0, sizeof(no[nodes]->child));
        return nodes++;
    }

    void clear() {
        nodes = 0;
        newnode();
    }

    void insert(string s, int id) {
        int atual = 0;
        for(int i = 0; i < s.size(); i++) {
            int c = get(s[i]);
            if(!no[atual]->child[c])
                no[atual]->child[c] = newnode();
            atual = no[atual]->child[c];
        }
        no[atual]->leaf = true;
        no[atual]->wid = id;
    }

    void getFails() {
        for(int i = 0; i < ALP_SIZ; i++)
            if(no[0]->child[i]) {
                no[ no[0]->child[i] ]->fail = 0, q.push(no[0]->child[i]);
                if(no[ no[0]->child[i] ]->leaf) no[ no[0]->child[i] ]->endLink = no[0]->child[i];
            }

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int i = 0; i < ALP_SIZ; i++) {
                int v = no[u]->child[i];
                if(!v) { no[u]->child[i] = no[no[u]->fail]->child[i]; continue; }

                q.push(v);
                int j = no[u]->fail;
                while(j && !no[j]->child[i]) j = no[j]->fail;
                no[v]->fail = no[j]->child[i];

                if(no[v]->leaf) no[v]->endLink = v;
                else no[v]->endLink = no[no[v]->fail]->endLink;
            }
        }
    }
} AC;

string pat[N];

int n, q, l, r, k;
char s[N];
string st, megazord;

map<string, int> id;
int pai[N], freq[N], L[N], R[N];

vector<int> occ[N];

void findOccurs(Automaton &AC, string s) {
    int atual = 0;

    for(int i = 0; i < s.size(); i++) {
        while(!(AC.no[atual])->child[get(s[i])] && atual != 0) atual = AC.no[atual]->fail;
        atual = (AC.no[atual])->child[get(s[i])];

        int aux = atual;
        while(true) {
            aux = (AC.no[aux])->endLink;
            if(aux == 0) break;
            occ[(AC.no[aux])->wid].push_back(i - pat[(AC.no[aux])->wid].size() + 1);
            // cout << pat[(AC.no[aux])->wid] << " found at position " << i - pat[(AC.no[aux])->wid].size() + 1 << endl;
            aux = (AC.no[aux])->fail;
        }
    }
}

int main() {
    AC.clear();

    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%s", s); pat[i] = s;

        if(!id.count(pat[i]))
            id[pat[i]] = i;

        pai[i] = id[pat[i]];
        freq[pai[i]]++;

        if(pai[i] == i)
            AC.insert(pat[i], i);

        L[i] = megazord.size() + 1;
        R[i] = megazord.size() + pat[i].size();
        megazord += "$" + pat[i];
    }
    AC.getFails();

    findOccurs(AC, megazord);

    while(q--) {
        scanf("%d %d %d", &l, &r, &k);
        k = pai[k-1], l = L[l - 1], r = R[r - 1];

        r = upper_bound(occ[k].begin(), occ[k].end(), r) - occ[k].begin() - 1;
        l = lower_bound(occ[k].begin(), occ[k].end(), l) - occ[k].begin();
        printf("%d\n", r - l + 1);
    }
    return 0;
}