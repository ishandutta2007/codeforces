#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

void pushright() {
	for (int i = 0; i < 10; i++)
		cout << '?' << i << ">>" << i << '?' << endl;
}

void startincr() {
	cout << "?>>??" << endl;
}

void addq() {
	for (int i = 0; i < 10; i++)
		cout << i << ">>?" << i << endl;
}

void incr() {
	for (int i = 0; i < 9; i++)
		cout << i << "??<>" << i + 1 << endl;
	cout << "9??>>??0" << endl;
	cout << "??<>1" << endl;
}

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	incr();
	pushright();
	startincr();
	addq();

	return 0;
}