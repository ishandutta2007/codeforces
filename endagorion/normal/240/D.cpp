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

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

int main() {
	fout.precision(10);
	fout << fixed;

    int N, M;
    fin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        fin >> A[i];
    }
    fin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        fin >> B[i];
    }
    int m0 = 0, m1 = 0;
    int cur = 0, i1 = 0, i2 = 0;
    while (i1 < A.size() || i2 < B.size()) {
        while (i1 < A.size() && A[i1] == cur) {
            ++i1;
        }
        while (i2 < B.size() && B[i2] == cur) {
            ++i2;
        }
        cur = 1 - cur;
        ++m0;
    }
    if (cur == 1) {
        --m0;
    }
    cur = 1, i1 = 0, i2 = 0;
    while (i1 < A.size() || i2 < B.size()) {
        while (i1 < A.size() && A[i1] == cur) {
            ++i1;
        }
        while (i2 < B.size() && B[i2] == cur) {
            ++i2;
        }
        cur = 1 - cur;
        ++m1;
    }
    if (cur == 1) {
        --m1;
    }
    int beg = (m0 < m1 ? 0 : 1);
    vector<int> total;
    cur = beg, i1 = 0, i2 = 0;
    while (i1 < A.size() || i2 < B.size()) {
        while (i1 < A.size() && A[i1] == cur) {
            total.push_back(cur);           
            fout << ++i1 << ' ';
        }
        while (i2 < B.size() && B[i2] == cur) {
            total.push_back(cur);
            fout << A.size() + ++i2 << ' ';          
        }
        cur = 1 - cur;
    }
    
    fout << '\n';
    int ans;
    fout << (ans = min(m0, m1)) << '\n';
    total.push_back(0);
    for (size_t i = 0; i + 1 < total.size(); ++i) {
        if (total[i] != total[i + 1]) {
            fout << i + 1 << ' ';       
        }      
    }

    fout << '\n';
    
	return 0;
}