#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string.h>
#include <cmath>


using namespace std;


int n;
int p[500];
string s[500];
bool used[100000];
int a[100000];


void dfs(int u) {
    //cout << u << endl;
    used[p[u]] = true;
    for (int j = 0; j < n; j++) {
        int g = p[j];
        if (!used[g] && s[u][j] == '1') {
            a[j] = u;
            dfs(j);
        }
    }
}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    //cout << "opa" << endl;
        for (int i = 0; i < n; i++) {
            int aa = p[i];
            int g = -1;
            for (int j = i + 1; j < n; j++) {
                if (aa > p[j]) {
                    for (int k = 0; k < n; k++) {
                        used[k] = 0;
                    }
                    a[i] = -1;
                    //cout << j << endl;
                    dfs(i);
                    if (used[p[j]]) {
                        aa = p[j];
                        g = j;
                       // cout << "opa" << endl;
                    }
                }
            }
            if (g != -1) {    
               // cout << i << endl;
                for (int k = 0; k < n; k++) {
                    used[k] = 0;
                }
                a[i] = -1;
                dfs(i);
               // cout << g << endl;
                swap(p[g], p[i]);
            }
        }
    //cout << a << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}