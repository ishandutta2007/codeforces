#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;


int n, m;
int x[200001];
int x1[200001];
map<int, int> mm;
map<int, int> ggg;



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x1[i]);
        x[i] = x1[i];
        ggg[x[i]] = i + 1;
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++) {
        mm[x[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, l;
        scanf("%d %d", &a, &l);
        a--;
        a = mm[x1[a]];
     // cout << a << endl;
        int t = 0;
        
               // cout << a + 1 << endl;
        //cout << l << endl;
        for (int k = 0; k < 60; k++) {
            if (t == 0) {
                int L1 = a;
                int R1 = n - 1;
                while (L1 != R1) {
                    int M = (L1 + R1 + 1) / 2;
                    if (x[M] - x[a] > l) {
                      R1 = M - 1;
                    } else {
                      L1 = M;
                    }
                 //   cout << "opa" << endl;
                }
          //  cout << "opa" << endl;
                int gg1 = x[L1] - x[a];
                a = L1;
                l -= gg1;
                t = 1 - t;
            } else {
                int L1 = a;
                int R1 = 0;
                while (L1 != R1) {
                    int M = (L1 + R1) / 2;
                    if (x[a] - x[M] > l) {
                      R1 = M + 1;
                    } else {
                      L1 = M;
                    }
                   // cout << "opa" << endl;
                }
          //  cout << "opa" << endl;
                int gg1 = x[a] - x[L1];
                a = L1;
                l -= gg1;
                t = 1 - t;
            }
           // cout << a + 1 << endl;
           // cout << "opa" << endl;
            if (t == 0) {
                int L = a;
                int R = n - 1;
                while (L != R) {
                    int M = (L + R + 1) / 2;
                    if (x[M] - x[a] > l) {
                        R = M - 1;
                    } else {
                        L = M;
                    }
                   // cout << "opa" << endl;
                }
              //  cout << "opa" << endl;
                int gg = x[L] - x[a];
                if (gg != 0) {
                    a = ((l / gg) % 2 == 0 ? a: L);
                    t = ((l / gg) % 2 == 0 ? t: 1 - t);
                    l = l % gg;
                } else {
                    t = 1 - t;
                }
                L = a;
                R = 0;
                while (L != R) {
                    int M = (L + R) / 2;
                    if (x[a] - x[M] > l) {
                        R = M + 1;
                    } else {
                        L = M;
                    }
                //    cout << "opa" << endl;
                }
               // cout << "opa" << endl;
                int hh = x[a] - x[L];
                if (hh != 0) {
                    a = ((l / hh) % 2 == 0 ? a: L);
                    t = ((l / hh) % 2 == 0 ? t: 1 - t);
                    l = l % hh;
                } else {
                    t = 1 - t;
                }
            }
            if (t == 1) {
                int L = a;
                int R = 0;
                while (L != R) {
                    int M = (L + R) / 2;
                    if (x[a] - x[M] > l) {
                        R = M + 1;
                    } else {
                        L = M;
                    }
                 //   cout << "opa" << endl;
                }
              //  cout << "opa" << endl;
                               // cout << L + 1 << endl;
                int gg = x[a] - x[L];
                if (gg != 0) {
                    a = ((l / gg) % 2 == 0 ? a: L);
                    t = ((l / gg) % 2 == 0 ? t: 1 - t);
                    l = l % gg;
                } else {
                    t = 1 - t;
                }
               // cout << a + 1 << endl;
                //cout << l << endl;
                L = a;
                R = 0;
                while (L != R) {
                    int M = (L + R) / 2;
                    if (x[M] - x[a] > l) {
                        R = M - 1;
                    } else {
                        L = M;
                    }
                    //cout << "opa" << endl;
                }
                //cout << "opa" << endl;
                int hh = x[L] - x[a];
                if (hh != 0) {
                    a = ((l / hh) % 2 == 0 ? a: L);
                    t = ((l / hh) % 2 == 0 ? t: 1 - t);
                    l = l % hh;
                } else {
                    t = 1 - t;
                }
            }   
          //  cout << a + 1 << endl;
        }
        printf("%d\n", ggg[x[a]]);
    }
    return 0;
}