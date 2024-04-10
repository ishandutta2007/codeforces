#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int n;
int a[150002];
bool good[150002];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> t;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (i != 0) {
                if (a[i] >= a[i - 1]) {
                    t.push_back(i);
                    good[i] = 1;
                    sum++;
                    t.push_back(i - 1);
                    good[i - 1] = 1;
                }
            }
            if (i != n - 1) {
                if (a[i] >= a[i + 1]) {
                    t.push_back(i);
                    good[i] = 1;
                    t.push_back(i + 1);
                    good[i + 1] = 1;
                    sum++;
                }
            }
        } else {
            if (i != 0) {
                if (a[i] <= a[i - 1]) {
                    t.push_back(i);
                    good[i] = 1;
                    t.push_back(i - 1);
                    good[i - 1] = 1;
                    sum++;
                }
            }
            if (i != n - 1) {
                if (a[i] <= a[i + 1]) {
                    t.push_back(i);
                    t.push_back(i + 1);
                    good[i + 1] = 1;
                    good[i] = 1;
                    sum++;
                }
            }
        }
    }
    sort(t.begin(), t.end());
    t.resize(distance(t.begin(), unique(t.begin(), t.end())));
    if ((int)t.size() > 60) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int ii = 0; ii < (int)t.size(); ii++) {
        int i = t[ii];
        for (int j = 0; j < n; j++) {
            if (i != j && !good[j]) {
                int sum1 = sum;
                if (i % 2 == 0) {
                    if (i != 0) {
                        if (a[i] >= a[i - 1]) {
                            sum1-= 2;
                        }
                    }
                    if (i != n - 1) {
                        if (a[i] >= a[i + 1]) {
                            sum1-= 2;
                        }
                    }
                } else {
                    if (i != 0) {
                        if (a[i] <= a[i - 1]) {
                            sum1-= 2;
                        }
                    }
                    if (i != n - 1) {
                        if (a[i] <= a[i + 1]) {
                            sum1-= 2;
                        }
                    }
                }
                if (j % 2 == 0) {
                    if (j != 0) {
                        if (j - 1 != i && a[j] >= a[j - 1]) {
                            sum1-= 2;
                        }
                    }
                    if (j != n - 1) {
                        if (j + 1 != i && a[j] >= a[j + 1]) {
                            sum1 -= 2;
                        }
                    }
                } else {
                    if (j != 0) {
                        if (j - 1 != i && a[j] <= a[j - 1]) {
                            sum1 -= 2;
                        }
                    }
                    if (j != n - 1) {
                        if (j + 1 != i && a[j] <= a[j + 1]) {
                            sum1 -= 2;
                        }
                    }
                }
                if (sum1 != 0) {
                    continue;
                }
                swap(a[i], a[j]);
                if (i % 2 == 0) {
                    if (i != 0) {
                        if (a[i] >= a[i - 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                    if (i != n - 1) {
                        if (a[i] >= a[i + 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                } else {
                    if (i != 0) {
                        if (a[i] <= a[i - 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                    if (i != n - 1) {
                        if (a[i] <= a[i + 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                }
                if (j % 2 == 0) {
                    if (j != 0) {
                        if (j - 1 != i && a[j] >= a[j - 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                    if (j != n - 1) {
                        if (j + 1 != i && a[j] >= a[j + 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                } else {
                    if (j != 0) {
                        if (j - 1 != i && a[j] <= a[j - 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                    if (j != n - 1) {
                        if (j + 1 != i && a[j] <= a[j + 1]) {
                            swap(a[i], a[j]);
                            continue;
                        }
                    }
                }
                if (sum1 == 0) {
                    ans++;
                }
                swap(a[i], a[j]);
            }
        }
    }
    for (int ii = 0; ii < (int)t.size(); ii++) {
        for (int jj = ii + 1; jj < (int)t.size(); jj++) {
            int i = t[ii];
            int j = t[jj];
            int sum1 = sum;
            if (i % 2 == 0) {
                if (i != 0) {
                    if (a[i] >= a[i - 1]) {
                        sum1-= 2;
                    }
                }
                if (i != n - 1) {
                    if (a[i] >= a[i + 1]) {
                        sum1-= 2;
                    }
                }
            } else {
                if (i != 0) {
                    if (a[i] <= a[i - 1]) {
                        sum1-= 2;
                    }
                }
                if (i != n - 1) {
                    if (a[i] <= a[i + 1]) {
                        sum1-= 2;
                    }
                }
            }
            if (j % 2 == 0) {
                if (j != 0) {
                    if (j - 1 != i && a[j] >= a[j - 1]) {
                        sum1-= 2;
                    }
                }
                if (j != n - 1) {
                    if (j + 1 != i && a[j] >= a[j + 1]) {
                        sum1 -= 2;
                    }
                }
            } else {
                if (j != 0) {
                    if (j - 1 != i && a[j] <= a[j - 1]) {
                        sum1 -= 2;
                    }
                }
                if (j != n - 1) {
                    if (j + 1 != i && a[j] <= a[j + 1]) {
                        sum1 -= 2;
                    }
                }
            }
            swap(a[i], a[j]);
            if (i % 2 == 0) {
                if (i != 0) {
                    if (a[i] >= a[i - 1]) {
                        sum1 += 2;
                    }
                }
                if (i != n - 1) {
                    if (a[i] >= a[i + 1]) {
                        sum1 += 2;
                    }
                }
            } else {
                if (i != 0) {
                    if (a[i] <= a[i - 1]) {
                        sum1 += 2;
                    }
                }
                if (i != n - 1) {
                    if (a[i] <= a[i + 1]) {
                        sum1 += 2;
                    }
                }
            }
            if (j % 2 == 0) {
                if (j != 0) {
                    if (j - 1 != i && a[j] >= a[j - 1]) {
                        sum1 += 2;
                    }
                }
                if (j != n - 1) {
                    if (j + 1 != i && a[j] >= a[j + 1]) {
                        sum1 += 2;
                    }
                }
            } else {
                if (j != 0) {
                    if (j - 1 != i && a[j] <= a[j - 1]) {
                        sum1 += 2;
                    }
                }
                if (j != n - 1) {
                    if (j + 1 != i && a[j] <= a[j + 1]) {
                        sum1 += 2;
                    }
                }
            }
            if (sum1 == 0) {
                ans++;
            }
            swap(a[i], a[j]);        
        }
    }
    cout << ans << endl;
    return 0;   
}