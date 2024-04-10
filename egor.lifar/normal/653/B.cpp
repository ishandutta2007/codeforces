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


int n, q;
string a[40], b[40];
int sum = 0;
vector<char> s;


void get(int i) {
    if (i == n) {
        vector<char> s1 = s;
        reverse(s1.begin(), s1.end());
        bool t = 1;
        for (int i = 0; i < n - 1; i++) {
            string c;
            c += s1.back();
            c += s1[(int)s1.size() - 2];
            bool bb = 1;
            for (int j = 0; j < q; j++) {
                if (a[j] == c) {
                    s1.pop_back();
                    s1.pop_back();
                    s1.push_back(b[j][0]);
                    bb = 0;
                    break;
                }
            }
            if (bb) {
                t = 0;
                break;
            }
        }
        if ((int)s1.size() == 1 && s1[0] == 'a') {
            sum += t;
        }
        return;
    }
    for (char a = 'a'; a <= 'f'; a++) {
        s.push_back(a);
        get(i + 1);
        s.pop_back(); 
    }
}
 

int main() {
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
    }
    get(0);
    cout << sum << endl;
    return 0;   
}