#include<bits/stdc++.h>

using namespace std;

int N;
char c[200][200];

int main() {
cin >> N;
for(int i = 0; i < N; i++) cin >> c[i];
bool good = true;
for(int i = 0; i < N; i++)
for(int j = 0; j < N; j++) {
int cnt = 0;
if(i > 0) cnt += c[i - 1][j] == 'o';
if(j > 0) cnt += c[i][j - 1] == 'o';
if(i < N - 1) cnt += c[i + 1][j] == 'o';
if(j < N - 1) cnt += c[i][j + 1] == 'o';
if(cnt % 2) good = false;
}
cout << (good ? "YES" : "NO") << '\n';
return 0;
}