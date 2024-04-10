#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

vector<string> stv;
string str;
char s[110];
int n;

bool cmp(string &a, string &b) {
    return a.size() < b.size();
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", s); str = s;
        stv.push_back(str);
    }
    sort(stv.begin(), stv.end(), cmp);

    int f = 1;
    for(int i = 0; i + 1 < n; i++) {
        if(stv[i+1].find(stv[i]) == -1) {
            f = 0;
            break;
        }
    }

    if(f) {
        printf("YES\n");
        for(int i = 0; i < n; i++) {
            printf("%s\n", stv[i].c_str());
        }
    } else printf("NO\n");
    return 0;
}