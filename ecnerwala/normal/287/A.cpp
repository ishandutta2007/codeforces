#include<iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
vector<string> v(4);
for (int i=0; i<4; i++) cin >> v[i];
for(int i = 0; i <= 2; i++) for(int j = 0; j <= 2; j++) {
int cnt = 0;
for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++) {
if (v[i+k][j+l] == '#') cnt++; }
if(cnt != 2) { cout << "YES\n"; return 0;}
} cout << "NO\n"; return 0;}