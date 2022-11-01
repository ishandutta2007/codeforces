#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k, id, nm[55];
vector<string> names(55), res(55);
string str[55];

string get_name(int id) {
    string ret = "";
    char c;
    while(id > 26) {
        c = char('a' + (id % 26));
        ret = c + ret;
        id /= 26;
    }
    c = char('A' + (id % 26));
    ret = c + ret;

    return ret;
}

void fill_(int l, int r) {
    for(int i=l;i<=r;i++) {
        if(nm[i]) continue;
        nm[i] = 1;
        res[i] = get_name(++id);
    }
}

int main() {
    scanf("%d %d",&n, &k);

    for(int i=1; i<= (n - k + 1); i++) {
        cin >> str[i];
    }

    for(int i=1; i<= (n - k + 1); i++) {
        if(str[i] == "YES") {
            fill_(i, i + k - 1);
        }
        else {
            fill_(i, i + k - 1);
            res[i + k - 1] = res[i];
        }
    }

    for(int i=1;i<=n;i++) {
        cout << res[i] << " ";
    }
    return 0;
}