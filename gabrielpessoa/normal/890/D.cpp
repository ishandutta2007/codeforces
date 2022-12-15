#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 1E5+5;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll fact = 1E9+7;

int palavra[SIZE];
int pos[30];
string s[SIZE];

bool conc(int a, int b) {
    char inicial = s[b][0];
    int pos = -1;
    for(int i = 0; i < s[a].length(); i++) {
        if(s[a][i] == s[b][0]) {
            pos = i;
            break;
        }
    }
    if(pos == -1) {
        return false;
    }
    for(int i = 0; i < s[b].length(); i++) {
        if(pos+i >= s[a].length()) {
            s[a] += s[b][i];
        } else if(s[a][pos+i] != s[b][i]) {
            return false;
        }
    }
    for(int i = 0; i < 26; i++) {
        if(palavra[i] == b) {
            palavra[i] = a;
        }
    }
    s[b] = "";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    memset(palavra, -1, sizeof(palavra));
    for(int c = 0; c < n; c++) {
        cin >> s[c];
        int i = c;
        if(s[i].length() > 26) {
            //printf("Debug 1\n");
            puts("NO");
            return 0;
        }
        for(char j = 'a'; j <= 'z'; j++) {
            if(count(s[i].begin(), s[i].end(), j)  > 1) {
                //printf("Debug 2\n");
                puts("NO");
                return 0;
            }
        }
        for(int j = 0; j < s[i].length(); j++) {
            int letra = s[i][j] - 'a';
            if(palavra[letra] == -1) {
                palavra[letra] = i;
            } else if(palavra[letra] == i) {
                continue;
            } else if(j == 0) {
                if(!conc(palavra[letra], i)) {
                    //printf("Debug 3\n");
                    puts("NO");
                    return 0;
                }
                i = palavra[letra];
            } else {
                if(!conc(i, palavra[letra])) {
                    //printf("Debug 4\n");
                    puts("NO");
                    return 0;
                }
            }
        }
        for(char j = 'a'; j <= 'z'; j++) {
            if(count(s[i].begin(), s[i].end(), j)  > 1) {
                //printf("Debug 2\n");
                puts("NO");
                return 0;
            }
        }
    }
    sort(s, s+n);
    for(int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}