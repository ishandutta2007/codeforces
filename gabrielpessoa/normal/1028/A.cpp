#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int ms = 1000;

string a[ms];

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> inicio = {1000, 1000}, fim = {-1, -1};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'B') {
                pair<int, int> pos = {i+1, j+1};
                inicio = min(inicio, pos); fim = max(inicio, pos);
            }
        }
    }
    cout << (fim.first+inicio.first)/2 << ' ' << (fim.second+inicio.second)/2 << '\n';
}