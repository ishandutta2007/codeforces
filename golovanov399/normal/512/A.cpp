#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int b[26][26];
vector<int> order;
char used[26];

void dfs(int v){
    used[v] = 1;
    for (int i = 0; i < 26; i++){
        if (b[v][i] == -1){
            if (!used[i])
                dfs(i);
            else if (used[i] == 1) {
                cout << "Impossible\n";
                exit(0);
            }
        }
    }
    order.pb(v);
    used[v] = 2;
}

int main(){

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            b[i][j] = 0;
        }
    }
    for (int i = 0; i < n - 1; i++){
        int j = 0;
        while (j < a[i].length() && j < a[i + 1].length() && a[i][j] == a[i + 1][j])
            j++;
        if (j == a[i + 1].length() && a[i].length() > a[i + 1].length()){
            cout << "Impossible\n";
            return 0;
        }
        if (j < a[i].length() && j < a[i + 1].length()){
            if (b[a[i][j] - 'a'][a[i + 1][j] - 'a'] == 1){
                cout << "Impossible\n";
                return 0;
            }
            b[a[i][j] - 'a'][a[i + 1][j] - 'a'] = -1;
            b[a[i + 1][j] - 'a'][a[i][j] - 'a'] = 1;
        }
    }
    for (int i = 0; i < 26; i++){
        if (!used[i])
            dfs(i);
    }
    reverse(all(order));
    for (int i = 0; i < 26; i++){
        cout << (char)('a' + order[i]);
    }
    cout << "\n";

    return 0;
}