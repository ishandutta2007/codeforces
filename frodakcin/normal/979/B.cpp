#include <iostream>
#include <cstdio>

#include <map>
#include <string>

using namespace std;

const int MAX_N = 1010000000;
const int MAX_STR = 1010000;

int N, strl;

string names[] = {"Kuro", "Shiro", "Katie"};
string draw = "Draw";

int main() {
	scanf("%d", &N);
	
	int curh = -1;
	
	string ans = "";
	
	getline(cin, ans);
	
	for(int i = 0;i < 3;i++) {
		char c;
		
		int tmax = 0; 
		
		map<char, int> apprates;
		
		string input;
		getline(cin, input);
		strl = input.length();
		
		for(int j = 0;j < input.length();j++) {
			char c = input[j];
			
			if(apprates.find(c) == apprates.end()) {
				apprates[c] = 1;
			} else {
				apprates[c]++;
			}
			
		}
		
		for(map<char, int>::iterator it = apprates.begin();it != apprates.end();it++) {
			int apr = it->second;
			
			if(N == 1 && apr == strl) {
				if(tmax < apr - 1) {
					tmax = apr - 1;
				}
			} else if(N + apr <= strl) {
				if(tmax < apr + N) {
					tmax = apr + N;
				}
			} else {
				if(tmax < strl) {
					tmax = strl;
				}
			}
		}
		
		if(tmax == curh) {
			ans = draw;
		} else if (tmax > curh) {
			curh = tmax;
			ans = names[i];
		}
		
	}
	
	printf("%s\n", ans.c_str());
}