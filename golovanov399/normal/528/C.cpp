#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<multiset<int>> ed;
vector<int> res;

void findEul(){
    vector<int> st;
    st.pb(0);
    while (!st.empty()){
        int v = st.back();
        if (ed[v].empty()){
            res.pb(v);
            st.pop_back();
        } else {
            int w = *(ed[v].begin());
            ed[v].erase(ed[v].begin());
            ed[w].erase(ed[w].find(v));
            st.pb(w);
        }
    }
}

int main(){

    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    vector<int> od;
    for (int i = 0; i < n; i++){
        if (a[i].size() & 1)
            od.pb(i);
    }
    for (int i = 0; i < od.size(); i += 2){
        a[od[i]].pb(od[i + 1]);
        a[od[i + 1]].pb(od[i]);
    }
    m += od.size() / 2;
    if (m & 1){
        a[0].pb(0);
        a[0].pb(0);
        m++;
    }
    ed.resize(n);
    for (int i = 0; i < n; i++)
        for (auto x : a[i])
            ed[i].insert(x);
    findEul();
    printf("%d\n", m);
    for (int i = 0; i < m; i++){
        int l = i;
        int r = i + 1;
        if (r == m)
            r = 0;
        if (l & 1)
            swap(l, r);
        printf("%d %d\n", res[l] + 1, res[r] + 1);
    }

    return 0;
}