#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n,k,siz = 1,gr[501005],gr2[501005];
char word[501005];

struct entry {
    int next[28],leaf;
} t[501005];

int dfs(int v) {
    if (!gr[v]) {
        int res = 1;
        bool was = false;
        for (int i = 0; i < 26; ++i) {
            if (t[v].next[i] != -1) {
                was = true;
                int qqq = dfs(t[v].next[i]);
                if (qqq == 1) {
                    res = 0;
                    break;
                }
            }
        }
        if (!was) gr[v] = 1 + 1;
        else gr[v] = res + 1;
    }
    return gr[v] - 1;
}

int dfs2(int v) {
    if (!gr2[v]) {
        int res = 1;
        bool was = false;
        for (int i = 0; i < 26; ++i) {
            if (t[v].next[i] != -1) {
                was = true;
                int qqq = dfs2(t[v].next[i]);
                if (qqq == 1) {
                    res = 0;
                    break;
                }
            }
        }
        if (!was) gr2[v] = 0 + 1;
        else gr2[v] = res + 1;
    }
    return gr2[v] - 1;
}

int main()
{
    cin >> n >> k;
    memset(t[0].next,255,sizeof(t[0].next));
    for (int i = 0; i < n; ++i) {
        cin >> word;
        int v = 0;
        int len = strlen(word);
        for (int j = 0; j < len; ++j) {
            int q = word[j] - 'a';
            if (t[v].next[q] == -1) {
                memset(t[siz].next, 255, sizeof(t[siz].next));
                t[v].next[q] = siz++;
            }
            v = t[v].next[q];
        }
        t[v].leaf = 1;
    }


    dfs(0);
    dfs2(0);

    int foo = 0; /// can win
    int foo2 = 0; /// can lose
    for (int i = 0; i < 26; ++i) {
        if (t[0].next[i] != -1 && dfs(t[0].next[i]) == 1)
            foo = 1;
        if (t[0].next[i] != -1 && dfs2(t[0].next[i]) == 1)
            foo2 = 1;
    }
    //cerr << foo;
    if (foo == 0) cout << "Second";
    else {
        if (foo2 == 0) cout << (k % 2 ? "First" : "Second");
        else {
            cout << "First";
        }
    }
    return 0;
}