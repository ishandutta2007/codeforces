#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n;
int parent[30], rank_[30];

char s[MN]; string str, str2;

int find(int node) {
    if(node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;

    if(rank_[a] > rank_[b]) {
        parent[b] = a;
        rank_[a] += rank_[b];
    }

    else {
        parent[a] = b;
        rank_[b] += rank_[a];
    }
    return true;
}

vector<pair<char, char> > ans;

int main() {
    scanf("%lld", &n);

    scanf("%s", s); str = s;
    scanf("%s", s); str2 = s;

    for(int i = 0; i < 27; i++) {
        parent[i] = i;
        rank_[i] = 1;
    }

    for(int i=0; i<n; i++) {
        if(str[i] != str2[i]) {
            if(join(str[i] - 'a', str2[i] - 'a')) {
                ans.push_back({str[i], str2[i]});
            }
        }
    }

    printf("%d\n", ans.size());
    for(auto pcc : ans) {
        printf("%c %c\n", pcc.first, pcc.second);
    }
    return 0;
}