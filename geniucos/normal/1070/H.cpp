#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 10011;
const int maxK = 11;
const int sigma = 26 + 10 + 1;

int id(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    if ('0' <= c && c <= '9') return 26 + c - '0';
    return 26 + 10;
}

struct node {
    int cnt, last;
    node* son[sigma];

    node() {
        cnt = last = 0;
        memset(son, 0, sizeof(son));
    }
};

int n, q, m, i, j;
char s[maxN][maxK], Q[maxK];
node* head;

void add_sub(char *s, int sz, int from) {
    node* act = head;
    int i, to;

    for (i = 1; i <= sz; i++) {
        to = id(s[i]);
        if (act->son[to] == NULL) 
            act->son[to] = new node();
        
        if (act->son[to]->last != from) {
            act->son[to]->cnt++;
            act->son[to]->last = from;
        }
        act = act->son[to];
    }
}

void add_word(int from, char *s) {
    int sz = strlen(s + 1);
    int i, j;

    for (i = 1; i <= sz; i++)
        add_sub(s + i - 1, sz - i + 1, from);
}

void query() {
    int i, j, sz, to;
    node* act;

    sz = strlen(Q + 1);
    act = head;

    for (i = 1; i <= sz; i++) {
        to = id(Q[i]);
        if (act->son[to] == NULL) {
            printf("0 -\n");
            return;
        }
        act = act->son[to];
    }

    printf("%d %s\n", act->cnt, s[act->last] + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    head = new node();
    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s\n", s[i] + 1);
        add_word(i, s[i]);
    }

    scanf("%d\n", &q);
    for (i = 1; i <= q; i++) {
        memset(Q, 0, sizeof(Q));
        scanf("%s\n", Q + 1);
        query();
    }


    return 0;
}