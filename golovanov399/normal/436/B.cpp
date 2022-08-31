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

using namespace std;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            if (s[j] == 'U'){
                if (i % 2 == 0){
                    a[j]++;
                }
            } else
            if (s[j] == 'L'){
                if (j - i >= 0){
                    a[j - i]++;
                }
            } else
            if (s[j] == 'R'){
                if (j + i < m){
                    a[j + i]++;
                }
            }
        }
    }
    for (int i = 0; i < m; i++){
        cout << a[i] << " ";
    }

    return 0;
    
}