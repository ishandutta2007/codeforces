#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

const int N = 8;

int X[N], Y[N];
pii pos[N];

bool good() {
    sort(X, X + N);
    sort(Y, Y + N);
    sort(pos, pos + N);
    if(unique(X, X + N) - X != 3) return false;
    if(unique(Y, Y + N) - Y != 3) return false;
    if(unique(pos, pos + N) - pos != 8) return false;
    for(int i = 0; i < N; i++) {
        if(pos[i] == pii(X[1], Y[1])) return false;
    }
    return true;
}

int main() {
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        pos[i].first = X[i], pos[i].second = Y[i];
    }
    if(good()) {
        cout << "respectable";
    } else cout << "ugly";
    cout << '\n';
}