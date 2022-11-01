#include <bits/stdc++.h>

using namespace std;

#define N 300100
#define ALP_SIZ 52

int get(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

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
} AC_inserted[20], AC_deleted[20];

int n, n_inserted, n_deleted;
vector<string> inserted_strs, deleted_strs;
string pat, st;
char s[300100];

int countOccurs(Automaton &AC, string s) {
    int atual = 0, ans = 0;

    for(int i = 0; i < s.size(); i++) {
        while(!(AC.no[atual])->child[get(s[i])] && atual != 0) atual = AC.no[atual]->fail;
        atual = (AC.no[atual])->child[get(s[i])];

        int aux = atual;
        while(true) {
            aux = (AC.no[aux])->endLink;
            if(aux == 0) break;

            ans++;
            aux = (AC.no[aux])->fail;
        }
    }

    return ans;
}

int query(string str) {
    int ans1 = 0, ans2 = 0;
    for(int i = 0; (1 << i) <= n_inserted; i++) {
        if((1 << i) & n_inserted)
            ans1 += countOccurs(AC_inserted[i], str);
    }

    //printf("%d\n", ans1);

    for(int i = 0; (1 << i) <= n_deleted; i++) {
        if((1 << i) & n_deleted)
            ans2 += countOccurs(AC_deleted[i], str);
    }

    return ans1 - ans2;
}

void insert(string s) {
    vector<string> to_insert; int id = 1;
    to_insert.push_back(s);

    int atual = 0, temp_n = n_inserted - 1;
    while((1 << atual) & n_inserted) {
        for(int i = temp_n; i > temp_n - (1 << atual); i--) {
            to_insert.push_back(inserted_strs[i]);
        }
        AC_inserted[atual].clear();
        temp_n -= (1 << atual);
        atual++;
    }

    AC_inserted[atual].clear();
    for(string str: to_insert) {
        AC_inserted[atual].insert(str, id++);
    }

    AC_inserted[atual].getFails();
    n_inserted++;
}

void remove(string s) {
    vector<string> to_insert; int id = 1;
    to_insert.push_back(s);

    int atual = 0, temp_n = n_deleted - 1;
    while((1 << atual) & n_deleted) {
        for(int i = temp_n; i > temp_n - (1 << atual); i--) {
            to_insert.push_back(deleted_strs[i]);
        }
        AC_deleted[atual].clear();
        temp_n -= (1 << atual);
        atual++;
    }

    AC_deleted[atual].clear();
    for(string str: to_insert) {
        AC_deleted[atual].insert(str, id++);
    }

    AC_deleted[atual].getFails();
    n_deleted++;
}

int t;

int main() {
    for(int i = 0; i < 20; i++) {
        AC_inserted[i].clear();
        AC_deleted[i].clear();
    }
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        scanf("%d %s", &t, s); pat = s;

        if(t == 1) {
            insert(pat);
            inserted_strs.push_back(pat);
        } else if(t == 2) {
            remove(pat);
            deleted_strs.push_back(pat);
        } else if(t == 3) {
            printf("%d\n", query(pat));
            fflush(stdout);
        } else assert(false);
    }
    return 0;
}