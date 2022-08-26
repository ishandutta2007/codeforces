#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


class Input
{
public:
	Input(std::istream& in);

	int readInt();

private:
	std::istream *in;
};

Input::Input(std::istream& in)
{
	this->in = &in;
}


inline int Input::readInt()
{
	int n;
	*in >> n;
	return n;
}

using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		Input inp(in);
		int n = inp.readInt();
		int t = inp.readInt();
		if (n == 1) {
			if (t == 10) {
				out << -1 << endl;
			} else {
				out << t << endl;
			}
		}
		else {
			int mod = 1;
			for (int i = 1; i < n; i++) {
				mod *= 10;
				mod %= t;
			}
			out << 1;
			for (int i = 2; i < n; i++)
				out << 0;
			out << (t - mod) % t << endl;
		}
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
#include <fstream>
#include <iostream>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;
    solve(in, out);
    return 0;
}