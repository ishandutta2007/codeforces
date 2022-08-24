#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt() - 1;
    vector<int> qw(n, 0);
    for (int i = 0; i < n; i++){
        if (a[i] == 0)
            qw[a[i]] = 1;
        else
            qw[a[i]] = qw[a[i] - 1] + 1;
    }

    cout << n - (*max_element(all(qw))) << "\n";

    return 0;
}