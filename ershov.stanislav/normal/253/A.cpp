#include <iostream>
#include <fstream>

using namespace std;
ifstream in;
ofstream out;
int main()
{
	in.open("input.txt");
	out.open("output.txt");
	int n, m;
	in >> n >> m;
	if (n>=m) {
		while (n+m) {
			if (n) out << 'B', n--;
			if (m) out << 'G', m--;
		}
	} else {
		while (n+m) {
			if (m) out << 'G', m--;
			if (n) out << 'B', n--;
		}
	}
    return 0;
}