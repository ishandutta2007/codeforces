#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt();
    vector<pair<int, int> > ar(n);
    for (int i = 0; i < n; i++)
        ar[i] = {a[i], i};
    sort(all(ar));
    vector<int> ans(n + 1);
    multiset<int> S;
    S.insert(-n);
    set<int> T;
    T.insert(-1);
    T.insert(n);
    int cur = n;
    for (int i = 0; i < n; i++){
        int ind = ar[i].second;
        auto it = T.lower_bound(ind);
        auto rt = it;
        --it;
        // cerr << *it << " " << *rt << " " << ind << " " << cur << "\n";
        // for (auto x : S)
        //  cerr << x << " ";
        // cerr << "\n";
        S.erase(S.find(*it - *rt + 1));
        S.insert(*it - ind + 1);
        S.insert(ind - *rt + 1);
        while (cur && -cur != *S.begin()){
            ans[cur--] = ar[i].first;
        }
        T.insert(ind);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    puts("");

    return 0;
}