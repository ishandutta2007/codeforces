#include <bits/stdc++.h>
using namespace std;
int query(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int r; cin >> r;
    return r;
}
void solve(int tc) {
    int n; cin >> n;
    int a[n+1], role[n+1];
    for(int i=1; i+2<=n; i+=3) a[i] = query(i, i+1, i+2);
    int imp, crew;
    for(int i=1; i<=n; i++) role[i] = -1;
    for(int i=1; i+5<=n; i+=3) {
        if(a[i] != a[i+3]) {
            a[i+1] = query(i+1, i+2, i+3), a[i+2] = query(i+2, i+3, i+4);
            for(int j=i; j<i+3; j++) {
                if(a[j] != a[j+1]) {
                    if(a[j] == 0) {
                        imp = j, crew = j+3;
                        role[j] = 0, role[j+3] = 1;
                    }
                    else {
                        imp = j+3, crew = j;
                        role[j+3] = 0, role[j] = 1;
                    }
                }
            }
            break;
        }
    }
    for(int i=1; i+2<=n; i+=3) {
        if(i == imp || i+1 == imp || i+2 == imp || i == crew || i+1 == crew || i+2 == crew) {
            for(int j=i; j<i+3; j++) {
                if(role[j] == -1) {
                    role[j] = query(imp, crew, j);
                }
            }
        }
        else if(a[i] == 0) {
            if(query(i, i+1, crew) == 1) {
                if(query(i, imp, crew) == 0) role[i] = 0, role[i+1] = 1;
                else role[i] = 1, role[i+1] = 0;
                role[i+2] = 0; 
            }
            else {
                role[i] = role[i+1] = 0;
                role[i+2] = query(i+2, imp, crew);
            }
        }
        else {
            if(query(i, i+1, imp) == 0) {
                if(query(i, imp, crew) == 0) role[i] = 0, role[i+1] = 1;
                else role[i] = 1, role[i+1] = 0;
                role[i+2] = 1; 
            }
            else {
                role[i] = role[i+1] = 1;
                role[i+2] = query(i+2, imp, crew);
            }
        }
    }
    cout << "! ";
    queue<int> q;
    for(int i=1; i<=n; i++) if(role[i] == 0) q.push(i);
    cout << q.size();
    while(q.size()) {
        cout << " " << q.front();
        q.pop();
    }
    cout << endl;
}
int main() {
    int T; cin >> T;
    for(int i=1; i<=T; i++) solve(i);
}