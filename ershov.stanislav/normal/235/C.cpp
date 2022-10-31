#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>

using namespace std;

#define max 1111111

struct state {
    int len, link;
    map<char, int> next;
    int cnt;
    bool used;
};

state sa[2*max];
int sz, last;

void saInit() {
    sz = last = 0;
    sa[0].link = -1;
    sa[0].len = 0;
    ++sz;
}

void saAdd(char c) {
    int cur = sz++;
    sa[cur].cnt = 1;
    sa[cur].len = sa[last].len+1;
    int p = last;
    for (; p!=-1 && !sa[p].next.count(c); p=sa[p].link) sa[p].next[c] = cur;
    if (p==-1) sa[cur].link=0;
    else {
        int q = sa[p].next[c];
        if (sa[p].len+1==sa[q].len)sa[cur].link=q;
        else {
            int clone = sz++;
            sa[clone].cnt = 0;
            sa[clone].len=sa[p].len+1;
            sa[clone].link=sa[q].link;
            sa[clone].next=sa[q].next;
            sa[q].link=sa[cur].link=clone;
            for (; p!=-1 && sa[p].next[c]==q; p=sa[p].link) sa[p].next[c]=clone;
        }
    }
    last=cur;
}

int main()
{
    string c;
    saInit();
    cin >> c;
    for (int i=0; i<c.length(); i++) saAdd(c[i]);
    vector<state*> d[max];
    for (int i=0; i!=sz; i++) d[sa[i].len].push_back(&sa[i]);
    for (int i=sa[last].len; i>=1; i--) for (int j=0; j<d[i].size(); j++) sa[d[i][j]->link].cnt+=d[i][j]->cnt;
    int z;
    cin >> z;
    for (int k=0; k<z; k++) {
        string str, s2;
        cin >> str;
        s2 = str+str;
        int p=0, i=0, j=0, n=str.length(), ans=0;
        int *u = new int[n];
        for (int i=0; i<n; i++) u[i]=-1;
        while (j<n) {
            while (!sa[p].next.count(s2[i])&&sa[p].link!=-1)p=sa[p].link, j=i-sa[p].len;
            if (!sa[p].next.count(s2[i]))i=j=i+1;
            while (sa[p].next.count(s2[i]) && i-j<n)p=sa[p].next[s2[i]], i++;
            if (i-j==n&&!sa[p].used) ans+=sa[p].cnt, sa[p].used=true, u[j] = p;
            if (sa[p].link!=-1 &&sa[sa[p].link].len>=n-1) p=sa[p].link;
            j++;
        }
        for (int i=0; i<n; i++) if (u[i]!=-1)sa[u[i]].used=false;
        cout << ans << endl;
    }
    return 0;
}