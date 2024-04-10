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
#include <assert.h>


using namespace std;


string s[8];
string s1[8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


bool gen() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++){
                int i1 = i + dy[k];
                int j1 = j + dx[k];
                if (i1 < 0 || j1 < 0 || i1 >= 8 || j1 >= 8) {
                    continue;
                }
                if (s1[i1][j1] == s1[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}


string right(string a, int k) {
    string b;
    for (int i = a.size() - k; i < a.size(); i++) {
        b = b + a[i];
    }
    for (int i = 0; i < a.size() - k; i++) {
        b = b + a[i];
    }
    return b;
}


int main(){
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            for (int j1 = 0; j1 < 2; j1++) {
                for (int j2 = 0; j2 < 2; j2++) {
                    for (int j3 = 0; j3 < 2; j3++) {
                        for (int j4 = 0; j4 < 2; j4++) {
                            for (int j5 = 0; j5 < 2; j5++) {
                                for (int j6 = 0; j6 < 2; j6++) {
                                    for (int j7 = 0; j7 < 2; j7++) {
                                        s1[0] = right(s[0], j);
                                        s1[1] = right(s[1], j1);
                                        s1[2] = right(s[2], j2);
                                        s1[3] = right(s[3], j3);
                                        s1[4] = right(s[4], j4);
                                        s1[5] = right(s[5], j5);
                                        s1[6] = right(s[6], j6);
                                        s1[7] = right(s[7], j7);
                                        if (gen()) {
                                            cout << "YES" << endl;
                                            return 0;
                                        }
                                    }
                                }   
                            }   
                        }   
                    }   
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}