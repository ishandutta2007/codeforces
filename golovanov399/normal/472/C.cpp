#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    vector<int> q(n);
    /*
    for (int i = 0; i < n; i++){
        q[p[i]] = i;
    }
    */
    q = p;
    string s = "";
    for (int i = 0; i < n; i++){
        int j = q[i];
        if (b[j] < a[j]) swap(a[j], b[j]);
        if (s < a[j]) s = a[j]; else
        if (s < b[j]) s = b[j]; else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}