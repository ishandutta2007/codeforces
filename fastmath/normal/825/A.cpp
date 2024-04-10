#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <random>
#include <string>


//mt19937 rnd(rand());
using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k = 0;
	string ans = "";
	for (int i = 0; i < n; ++i){
		if (s[i] == '0'){
			ans += (char) (k + 48);
			k = 0;
		}
		else{
			++k;
		}
	}

	ans += (char)(k + 48);
	cout << ans;
	return 0;
}