#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

int main() {
	string s[100];
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	vector<char> v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int t = 0;
			for(int k = 0; k < n; k++){
				if(s[k][j] == s[i][j]){
					t++;
				}
			}
			for(int k = 0; k < m; k++){
				if(s[i][k] == s[i][j]){
					t++;
				}
			}
			if(t == 2){
				v.push_back(s[i][j]);
			}

		}
	}
	int l = (int)v.size();
	for(int i = 0; i < l; i++){
		printf("%c", v[i]);
	}
	printf("\n");
}