#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
ifstream in;
ofstream out;
int a[5555], n;
vector<pair<int, int> > v;
int main()
{
	in.open("input.txt");
	out.open("output.txt");
	in >> n;
	for (int i=0; i<2*n; i++) {
		int b;
		in >> b;
		if (a[b]==0) a[b]=i+1;
		else v.push_back(make_pair(a[b], i+1)), a[b]=0;
	}
	bool t=true;
	for (int i=0; i<5001; i++) if (a[i]) t=false;
	if (t) {
		for (int i=0; i<v.size(); i++) out << v[i].first << ' ' << v[i].second << endl;
	} else out << -1;
    return 0;
}