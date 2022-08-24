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
#define double long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int f(char c){
    if (c == 'R') return 0; else
    if (c == 'W') return 1; else
    if (c == 'B') return 2; else
    if (c == 'G') return 3; else
    return 4;
}

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n;
    cin >> n;
    bool a[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) a[i][j] = false;
    }
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        a[f(s[0])][s[1] - '1'] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (a[i][j]) cnt++;
        }
    }
    int m = 10;
    for (int i = 0; i < 1024; i++){
        set<int> s;
        for (int j = 0; j < 5; j++){
            for (int ij = 0; ij < 5; ij++){
                if (a[j][ij]){
                    int k = 0;
                    if (i & (1 << j)) k += (1 << j);
                    if (i & (1 << (ij + 5))) k += (1 << (ij + 5));
                    s.insert(k);
                }
            }
        }
        if (s.size() == cnt){
            m = min(m, __builtin_popcount(i));
        }
    }
    cout << m << "\n";

    return 0;
    
}