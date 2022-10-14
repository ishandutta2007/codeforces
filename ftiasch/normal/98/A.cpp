#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

const int r[3][4] = {{0, 1, 2, 3}, {0, 4, 2, 5}, {1, 4, 3, 5}};

string c;
set<string> s;

string change(string s, int a, int b, int c){
	string t = s;
	for(int i = 0; i < 4; ++ i){
		t[r[0][i]] = s[r[0][(i + a) % 4]];
	}
	s = t;
	for(int i = 0; i < 4; ++ i){
		t[r[1][i]] = s[r[1][(i + b) % 4]];
	}
	s = t;
	for(int i = 0; i < 4; ++ i){
		t[r[2][i]] = s[r[2][(i + c) % 4]];
	}
	return t;
}

int main(){
	cin >> c;
	sort(c.begin(), c.end());
	do{
		string m = c;
		for(int i = 0; i < 4; ++ i){
			for(int j = 0; j < 4; ++ j){
				for(int k = 0; k < 4; ++ k){
					m = min(m, change(c, i, j, k));
				}
			}
		}
		s.insert(m);
	}while(next_permutation(c.begin(), c.end()));
	cout << s.size() << endl;
	return 0;
}