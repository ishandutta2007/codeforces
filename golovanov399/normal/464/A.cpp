#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<char> a;
    for (int i = 0; i < s.length(); i++) a.pb(s[i]);
    int i = s.length() - 1;
    while (i >= 0){
        do {
            a[i]++;
        } while (((i > 0 && a[i] == a[i - 1]) || (i > 1 && a[i] == a[i - 2])) && a[i] - 'a' < p);
        if (a[i] - 'a' >= p){
            a[i] = 'a';
            i--;
        } else break;
    }
    if (i < 0){
        cout << "NO\n";
        return 0;
    }
    i++;
    while (i < n){
        while (a[i] - 'a' < p && ((i > 0 && a[i] == a[i - 1]) || (i > 1 && a[i] == a[i - 2]))) a[i]++;
        if (a[i] - 'a' >= p){
            cout << "NO\n";
            return 0;
        }
        i++;
    }
    for (int i = 0; i < n; i++) cout << a[i];
    cout << "\n";
    
    return 0;
}