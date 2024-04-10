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

bool match(char c1, char c2) {
    string s(2, 'a');
    s[0] = c1;
    s[1] = c2;
    return s == "()" || s == "[]";
}

int main() {
	fout.precision(10);
	fout << fixed;

    string s;
    fin >> s;
    vector< pair<int, char> > st;
    vector<int> b(s.length(), -1), sq(s.length(), 0);
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[') {
            st.push_back(make_pair(i, s[i]));
        } else {
            if (!st.empty() && match(st.back().second, s[i])) {
                b[i] = st.back().first;
                sq[i] = sq[i - 1];
                if (s[i] == ']') {
                    ++sq[i];
                }
                while (b[i] > 0 && b[b[i] - 1] >= 0) {
                    sq[i] += sq[b[i] - 1];
                    b[i] = b[b[i] - 1];
                }
                st.pop_back();
            } else {
                while (!st.empty()) {
                    st.pop_back();
                }
            }
        }
    }

    int m = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (sq[i] > sq[m]) {
            m = i;
        }
    }
    fout << sq[m] << '\n';
    if (sq[m] > 0) {
        for (int i = b[m]; i <= m; ++i) {
            fout << s[i];
        }     
    }
    fout << '\n';
    return 0;
}