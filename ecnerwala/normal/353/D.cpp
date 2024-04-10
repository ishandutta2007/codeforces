#include<iostream>
#include<cstring>

using namespace std;

char s[2000000];

int go() {
int N = strlen(s);
int F = 0;
for(int i = 0; i < N; i++) F += (s[i] == 'F');
int ans = 0;
int j = 0;
for(int i = 0; i < N; i++) {
 if(s[i] == 'F') {
if(i > j) {
int t = (F - 1 - j) + (i - j);
if(t > ans) ans = t;
} 
j++;
}
}
return ans;
}

int main() {
cin >> s;
cout << go() << '\n';
return 0;
}