#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, flag = 1;
char s[MN]; string str[55], st;
set<string> shifts;
map<pair<string, string>, int> dist;

int calc_d(string a, string b) {
    if(dist.find({a, b}) != dist.end()) return dist[{a, b}];
    string z = a;

    int d = 0;
    while(a != b) {
        char c = a[0];
        a = a.substr(1) + c;
        d++;
    }

    return dist[{z,b}] = d;
}

int main() {
    scanf("%d", &n);

    scanf("%s", s);
    str[0] = s;
    st = s;

    for(int k=0;k<55;k++) {
        shifts.insert(st);
        char c = st[0];
        st = st.substr(1) + c;
    }

    for(int i=1;i<n;i++) {
        scanf("%s", s);
        str[i] = s;

        if(!shifts.count(str[i])) flag = 0;
    }

    if(!flag) {
        printf("-1\n");
        return 0;
    }

    int ans = 99999999;
    for(auto shft : shifts) {
        int tot = 0;
        for(int i=0;i<n;i++) {
            tot += calc_d(str[i], shft);
        }
        ans = min(ans, tot);
    }

    printf("%d\n", ans);
}