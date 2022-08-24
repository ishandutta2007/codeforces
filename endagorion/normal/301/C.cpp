#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;


int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < 9; ++i) {
        cout << i << "??<>" << i + 1 << '\n';
    }
    cout << "9??>>??0\n";
    cout << "??<>1\n";

    for (int i = 0; i < 10; ++i) {
        cout << "?" << i << ">>" << i << "?\n";
    }
    cout << "?>>??\n";

    cout << ">>?" << '\n';
    
	return 0;
}