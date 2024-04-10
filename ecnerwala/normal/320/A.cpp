#include<iostream>

#include<cstring>

using namespace std;
char stuff[1000];
int main() {
cin >> stuff;
int n = strlen(stuff);
int count4 = 0;
for(int i = 0; i < n; i++) {
if(stuff[i] != '1'){
cout << "NO\n"; return 0;}
if(stuff[i] == '1'){
for(count4 = 0; count4 + i + 1 < n && stuff[count4 + i + 1] == '4'; count4++);
if(count4 >= 3){cout << "NO\n"; return 0;}
i += count4;}}
cout << "YES\n"; return 0;}