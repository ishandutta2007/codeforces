#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	map<string, string> mp;
	mp["00000000"] = "!x&x";
	mp["00000001"] = "x&y&z";
	mp["00000010"] = "!z&x&y";
	mp["00000011"] = "x&y";
	mp["00000100"] = "!y&x&z";
	mp["00000101"] = "x&z";
	mp["00000110"] = "!y&x&z|!z&x&y";
	mp["00000111"] = "(y|z)&x";
	mp["00001000"] = "!y&!z&x";
	mp["00001001"] = "!y&!z&x|x&y&z";
	mp["00001010"] = "!z&x";
	mp["00001011"] = "!z&x|x&y";
	mp["00001100"] = "!y&x";
	mp["00001101"] = "!y&x|x&z";
	mp["00001110"] = "!(y&z)&x";
	mp["00001111"] = "x";
	mp["00010000"] = "!x&y&z";
	mp["00010001"] = "y&z";
	mp["00010010"] = "!x&y&z|!z&x&y";
	mp["00010011"] = "(x|z)&y";
	mp["00010100"] = "!x&y&z|!y&x&z";
	mp["00010101"] = "(x|y)&z";
	mp["00010110"] = "!x&y&z|!y&x&z|!z&x&y";
	mp["00010111"] = "(x|y)&z|x&y";
	mp["00011000"] = "!x&y&z|!y&!z&x";
	mp["00011001"] = "!y&!z&x|y&z";
	mp["00011010"] = "!x&y&z|!z&x";
	mp["00011011"] = "!z&x|y&z";
	mp["00011100"] = "!x&y&z|!y&x";
	mp["00011101"] = "!y&x|y&z";
	mp["00011110"] = "!(y&z)&x|!x&y&z";
	mp["00011111"] = "x|y&z";
	mp["00100000"] = "!x&!z&y";
	mp["00100001"] = "!x&!z&y|x&y&z";
	mp["00100010"] = "!z&y";
	mp["00100011"] = "!z&y|x&y";
	mp["00100100"] = "!x&!z&y|!y&x&z";
	mp["00100101"] = "!x&!z&y|x&z";
	mp["00100110"] = "!y&x&z|!z&y";
	mp["00100111"] = "!z&y|x&z";
	mp["00101000"] = "!(!x&!y|x&y|z)";
	mp["00101001"] = "!(!x&!y|x&y|z)|x&y&z";
	mp["00101010"] = "!z&(x|y)";
	mp["00101011"] = "!z&(x|y)|x&y";
	mp["00101100"] = "!x&!z&y|!y&x";
	mp["00101101"] = "!x&!z&y|!y&x|x&z";
	mp["00101110"] = "!y&x|!z&y";
	mp["00101111"] = "!z&y|x";
	mp["00110000"] = "!x&y";
	mp["00110001"] = "!x&y|y&z";
	mp["00110010"] = "!(x&z)&y";
	mp["00110011"] = "y";
	mp["00110100"] = "!x&y|!y&x&z";
	mp["00110101"] = "!x&y|x&z";
	mp["00110110"] = "!(x&z)&y|!y&x&z";
	mp["00110111"] = "x&z|y";
	mp["00111000"] = "!x&y|!y&!z&x";
	mp["00111001"] = "!x&y|!y&!z&x|y&z";
	mp["00111010"] = "!x&y|!z&x";
	mp["00111011"] = "!z&x|y";
	mp["00111100"] = "!x&y|!y&x";
	mp["00111101"] = "!x&y|!y&x|x&z";
	mp["00111110"] = "!(x&z)&y|!y&x";
	mp["00111111"] = "x|y";
	mp["01000000"] = "!x&!y&z";
	mp["01000001"] = "!x&!y&z|x&y&z";
	mp["01000010"] = "!x&!y&z|!z&x&y";
	mp["01000011"] = "!x&!y&z|x&y";
	mp["01000100"] = "!y&z";
	mp["01000101"] = "!y&z|x&z";
	mp["01000110"] = "!y&z|!z&x&y";
	mp["01000111"] = "!y&z|x&y";
	mp["01001000"] = "!(!x&!z|x&z|y)";
	mp["01001001"] = "!(!x&!z|x&z|y)|x&y&z";
	mp["01001010"] = "!x&!y&z|!z&x";
	mp["01001011"] = "!x&!y&z|!z&x|x&y";
	mp["01001100"] = "!y&(x|z)";
	mp["01001101"] = "!y&(x|z)|x&z";
	mp["01001110"] = "!y&z|!z&x";
	mp["01001111"] = "!y&z|x";
	mp["01010000"] = "!x&z";
	mp["01010001"] = "!x&z|y&z";
	mp["01010010"] = "!x&z|!z&x&y";
	mp["01010011"] = "!x&z|x&y";
	mp["01010100"] = "!(x&y)&z";
	mp["01010101"] = "z";
	mp["01010110"] = "!(x&y)&z|!z&x&y";
	mp["01010111"] = "x&y|z";
	mp["01011000"] = "!x&z|!y&!z&x";
	mp["01011001"] = "!x&z|!y&!z&x|y&z";
	mp["01011010"] = "!x&z|!z&x";
	mp["01011011"] = "!x&z|!z&x|x&y";
	mp["01011100"] = "!x&z|!y&x";
	mp["01011101"] = "!y&x|z";
	mp["01011110"] = "!(x&y)&z|!z&x";
	mp["01011111"] = "x|z";
	mp["01100000"] = "!(!y&!z|x|y&z)";
	mp["01100001"] = "!(!y&!z|x|y&z)|x&y&z";
	mp["01100010"] = "!x&!y&z|!z&y";
	mp["01100011"] = "!x&!y&z|!z&y|x&y";
	mp["01100100"] = "!x&!z&y|!y&z";
	mp["01100101"] = "!x&!z&y|!y&z|x&z";
	mp["01100110"] = "!y&z|!z&y";
	mp["01100111"] = "!y&z|!z&y|x&y";
	mp["01101000"] = "!(!x&!y|x&y|z)|!x&!y&z";
	mp["01101001"] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
	mp["01101010"] = "!x&!y&z|!z&(x|y)";
	mp["01101011"] = "!x&!y&z|!z&(x|y)|x&y";
	mp["01101100"] = "!x&!z&y|!y&(x|z)";
	mp["01101101"] = "!x&!z&y|!y&(x|z)|x&z";
	mp["01101110"] = "!y&(x|z)|!z&y";
	mp["01101111"] = "!y&z|!z&y|x";
	mp["01110000"] = "!x&(y|z)";
	mp["01110001"] = "!x&(y|z)|y&z";
	mp["01110010"] = "!x&z|!z&y";
	mp["01110011"] = "!x&z|y";
	mp["01110100"] = "!x&y|!y&z";
	mp["01110101"] = "!x&y|z";
	mp["01110110"] = "!(x&y)&z|!z&y";
	mp["01110111"] = "y|z";
	mp["01111000"] = "!x&(y|z)|!y&!z&x";
	mp["01111001"] = "!x&(y|z)|!y&!z&x|y&z";
	mp["01111010"] = "!x&(y|z)|!z&x";
	mp["01111011"] = "!x&z|!z&x|y";
	mp["01111100"] = "!x&(y|z)|!y&x";
	mp["01111101"] = "!x&y|!y&x|z";
	mp["01111110"] = "!x&y|!y&z|!z&x";
	mp["01111111"] = "x|y|z";
	mp["10000000"] = "!(x|y|z)";
	mp["10000001"] = "!(x|y|z)|x&y&z";
	mp["10000010"] = "!(!x&y|!y&x|z)";
	mp["10000011"] = "!(x|y|z)|x&y";
	mp["10000100"] = "!(!x&z|!z&x|y)";
	mp["10000101"] = "!(x|y|z)|x&z";
	mp["10000110"] = "!(!x&y|!y&x|z)|!y&x&z";
	mp["10000111"] = "!(x|y|z)|(y|z)&x";
	mp["10001000"] = "!y&!z";
	mp["10001001"] = "!y&!z|x&y&z";
	mp["10001010"] = "!(!x&y|z)";
	mp["10001011"] = "!y&!z|x&y";
	mp["10001100"] = "!(!x&z|y)";
	mp["10001101"] = "!y&!z|x&z";
	mp["10001110"] = "!(!x&y|z)|!y&x";
	mp["10001111"] = "!y&!z|x";
	mp["10010000"] = "!(!y&z|!z&y|x)";
	mp["10010001"] = "!(x|y|z)|y&z";
	mp["10010010"] = "!(!x&y|!y&x|z)|!x&y&z";
	mp["10010011"] = "!(x|y|z)|(x|z)&y";
	mp["10010100"] = "!(!x&z|!z&x|y)|!x&y&z";
	mp["10010101"] = "!(x|y|z)|(x|y)&z";
	mp["10010110"] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
	mp["10010111"] = "!(x|y|z)|(x|y)&z|x&y";
	mp["10011000"] = "!x&y&z|!y&!z";
	mp["10011001"] = "!y&!z|y&z";
	mp["10011010"] = "!(!x&y|z)|!x&y&z";
	mp["10011011"] = "!(!x&y|z)|y&z";
	mp["10011100"] = "!(!x&z|y)|!x&y&z";
	mp["10011101"] = "!(!x&z|y)|y&z";
	mp["10011110"] = "!(!x&y|z)|!x&y&z|!y&x";
	mp["10011111"] = "!y&!z|x|y&z";
	mp["10100000"] = "!x&!z";
	mp["10100001"] = "!x&!z|x&y&z";
	mp["10100010"] = "!(!y&x|z)";
	mp["10100011"] = "!x&!z|x&y";
	mp["10100100"] = "!x&!z|!y&x&z";
	mp["10100101"] = "!x&!z|x&z";
	mp["10100110"] = "!(!y&x|z)|!y&x&z";
	mp["10100111"] = "!(!y&x|z)|x&z";
	mp["10101000"] = "!(x&y|z)";
	mp["10101001"] = "!(x&y|z)|x&y&z";
	mp["10101010"] = "!z";
	mp["10101011"] = "!z|x&y";
	mp["10101100"] = "!x&!z|!y&x";
	mp["10101101"] = "!(x&y|z)|x&z";
	mp["10101110"] = "!y&x|!z";
	mp["10101111"] = "!z|x";
	mp["10110000"] = "!(!y&z|x)";
	mp["10110001"] = "!x&!z|y&z";
	mp["10110010"] = "!(!y&x|z)|!x&y";
	mp["10110011"] = "!x&!z|y";
	mp["10110100"] = "!(!y&z|x)|!y&x&z";
	mp["10110101"] = "!(!y&z|x)|x&z";
	mp["10110110"] = "!(!y&x|z)|!x&y|!y&x&z";
	mp["10110111"] = "!x&!z|x&z|y";
	mp["10111000"] = "!x&y|!y&!z";
	mp["10111001"] = "!(x&y|z)|y&z";
	mp["10111010"] = "!x&y|!z";
	mp["10111011"] = "!z|y";
	mp["10111100"] = "!(!x&!y&z|x&y)";
	mp["10111101"] = "!x&!z|!y&x|y&z";
	mp["10111110"] = "!x&y|!y&x|!z";
	mp["10111111"] = "!z|x|y";
	mp["11000000"] = "!x&!y";
	mp["11000001"] = "!x&!y|x&y&z";
	mp["11000010"] = "!x&!y|!z&x&y";
	mp["11000011"] = "!x&!y|x&y";
	mp["11000100"] = "!(!z&x|y)";
	mp["11000101"] = "!x&!y|x&z";
	mp["11000110"] = "!(!z&x|y)|!z&x&y";
	mp["11000111"] = "!(!z&x|y)|x&y";
	mp["11001000"] = "!(x&z|y)";
	mp["11001001"] = "!(x&z|y)|x&y&z";
	mp["11001010"] = "!x&!y|!z&x";
	mp["11001011"] = "!(x&z|y)|x&y";
	mp["11001100"] = "!y";
	mp["11001101"] = "!y|x&z";
	mp["11001110"] = "!y|!z&x";
	mp["11001111"] = "!y|x";
	mp["11010000"] = "!(!z&y|x)";
	mp["11010001"] = "!x&!y|y&z";
	mp["11010010"] = "!(!z&y|x)|!z&x&y";
	mp["11010011"] = "!(!z&y|x)|x&y";
	mp["11010100"] = "!(!z&x|y)|!x&z";
	mp["11010101"] = "!x&!y|z";
	mp["11010110"] = "!(!z&x|y)|!x&z|!z&x&y";
	mp["11010111"] = "!x&!y|x&y|z";
	mp["11011000"] = "!x&z|!y&!z";
	mp["11011001"] = "!(x&z|y)|y&z";
	mp["11011010"] = "!(!x&!z&y|x&z)";
	mp["11011011"] = "!x&!y|!z&x|y&z";
	mp["11011100"] = "!x&z|!y";
	mp["11011101"] = "!y|z";
	mp["11011110"] = "!x&z|!y|!z&x";
	mp["11011111"] = "!y|x|z";
	mp["11100000"] = "!(x|y&z)";
	mp["11100001"] = "!(x|y&z)|x&y&z";
	mp["11100010"] = "!x&!y|!z&y";
	mp["11100011"] = "!(x|y&z)|x&y";
	mp["11100100"] = "!x&!z|!y&z";
	mp["11100101"] = "!(x|y&z)|x&z";
	mp["11100110"] = "!(!y&!z&x|y&z)";
	mp["11100111"] = "!x&!y|!z&y|x&z";
	mp["11101000"] = "!((x|y)&z|x&y)";
	mp["11101001"] = "!((x|y)&z|x&y)|x&y&z";
	mp["11101010"] = "!x&!y|!z";
	mp["11101011"] = "!x&!y|!z|x&y";
	mp["11101100"] = "!x&!z|!y";
	mp["11101101"] = "!x&!z|!y|x&z";
	mp["11101110"] = "!y|!z";
	mp["11101111"] = "!y|!z|x";
	mp["11110000"] = "!x";
	mp["11110001"] = "!x|y&z";
	mp["11110010"] = "!x|!z&y";
	mp["11110011"] = "!x|y";
	mp["11110100"] = "!x|!y&z";
	mp["11110101"] = "!x|z";
	mp["11110110"] = "!x|!y&z|!z&y";
	mp["11110111"] = "!x|y|z";
	mp["11111000"] = "!x|!y&!z";
	mp["11111001"] = "!x|!y&!z|y&z";
	mp["11111010"] = "!x|!z";
	mp["11111011"] = "!x|!z|y";
	mp["11111100"] = "!x|!y";
	mp["11111101"] = "!x|!y|z";
	mp["11111110"] = "!(x&y&z)";
	mp["11111111"] = "!x|x";
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		cout << mp[s] << endl;
	}
	return 0;
}