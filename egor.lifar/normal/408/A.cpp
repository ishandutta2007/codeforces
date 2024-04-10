#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n;
int k[100];
vector<int> v[100];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[i]; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    long long s = 1000000000;
    for (int i = 0; i < n; i++) {
        long long s1 = 0;
        for (int j = 0; j < k[i]; j++) {
            s1 += v[i][j] * 5;
            s1 += 15;
        }
        s = min(s, s1);
    }
    cout << s << endl;
	return 0;
}