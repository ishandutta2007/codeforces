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
	int N;
	fin >> N;
	vector<string> dirs;

	for (int i = 0; i < N; ++i) {
		string command;
		fin >> command;
		if (command == "pwd") {
			fout << '/';
			for (size_t i = 0; i < dirs.size(); ++i) {
				fout << dirs[i] << '/';
			}
			fout << '\n';
		}
		if (command == "cd") {
			string nextDir;
			fin >> nextDir;
			if (nextDir != "/") {
				nextDir += '/';
			}
			string curDir = "";
			for (size_t j = 0; j < nextDir.size(); ++j) {
				if (nextDir[j] == '/') {
					if (j == 0) {
						dirs.clear();
						continue;
					}
					if (curDir == "..") {
						dirs.pop_back();
					} else {
						dirs.push_back(curDir);
					}
					curDir = "";
				} else {
					curDir += nextDir[j];
				}
			}
		}
	}

	return 0;
}