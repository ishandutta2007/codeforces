#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

map <int, int> name;
map <int, int> dp;
vector<string> depth[1000100];
string st;
int qtd, i, best = -1;

int sto(string s) {
    int sm = 0;
    for(int i=0;i<s.size();i++) {
        sm = sm*10 + (s[i]-'0');
    }
    return sm;
}

void get(int parent) {
    int n = st.size();
     for(; i<n; i) {
        string a = "";
        while(i < n && st[i] != ',') {
            a += st[i];
            i++;
        }
        int z = i - a.size();
        name[z] = qtd++;
        dp[name[z]] = dp[parent] + 1;
        best = max(best, dp[name[z]]);

        depth[dp[name[z]]].push_back(a);

        i++;
        string rep = "";
        while(i < n && st[i] != ',') {
            rep += st[i];
            i++;
        } i++;

        int r = sto(rep);
        for(int j=0;j<r;j++) {
            get(name[z]);
        }
        if(parent != -1) return;
    }
}

int main() {
    char n[1000100];
    scanf("%s",n);//
    st = n;

    dp[-1] = 0;
    get(-1);

    printf("%d\n", best);
    for(int z=1; z <= best; z++) {
        for(int j=0;j<depth[z].size();j++) {
            printf("%s ", depth[z][j].c_str());
        } puts("");
    }
    return 0;
}