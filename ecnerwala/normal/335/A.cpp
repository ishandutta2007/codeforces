#include<iostream>

using namespace std;

const int L = 26;

int N;
int num[L];

bool isGood(int s) {
int cnt = 0;
for(int i = 0; i < L; i++) cnt += (num[i] + s - 1) / s;
return cnt <= N;
}

int bSearch() {
if(!isGood(2000)) return -1;
int min = 0, max =2000;
while(max - min > 1) {
int mid = (max + min) / 2;
if(isGood(mid)) max = mid;
else min = mid;
}
return max;
}

int main() {
string s; cin >> s;
cin >> N;
for(int i = 0; i < s.size(); i++) num[s[i] - 'a'] ++;
int ans = bSearch();
cout << ans << '\n';
if(ans != -1) 
{
for(int i = 0; i < L; i++) 
for(int j = 0; j < (num[i] + ans - 1) / ans; j++) 
cout << char(i + 'a'), N--;
for(; N > 0; N--) cout << 'a';
cout << '\n';
}
}