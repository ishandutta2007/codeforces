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

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	fout.precision(10);
	fout << fixed;

    int N;
    fin >> N;
    vector<bool> reach(2000000);
    vector<int> stack;
    for (int i = 0; i < N; ++i) {
        int x;
        fin >> x;
        stack.push_back(x);
        for (size_t j = 0; j < stack.size(); ++j) {
            stack[j] |= x;
            reach[stack[j]] = true;
        }
        for (size_t j = 0; j + 1 < stack.size(); ++j) {
            while (j + 1 < stack.size() && stack[j] == stack[j + 1]) {
                stack.erase(stack.begin() + j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2000000; ++i) {
        if (reach[i]) {
            ++ans;
        }
    }
    fout << ans << '\n';        

	return 0;
}