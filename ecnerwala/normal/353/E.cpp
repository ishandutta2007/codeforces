#include<iostream>
#include<cstring>
using namespace std;

char s[2000000];
int n;

inline int nxt(int i) { return (i + 1) % n; }

int go() {
int st = -1;
for(int i = 0; i < n; i++) {
if(s[i] == s[nxt(i)]) {
st = i;
}
}

if(st == -1) return n / 2;
int ans = 1;
char prv = s[nxt(st)];
int i;
for(i = (st + 2) % n; i != st && i != nxt(st); i = nxt(i)) {
if(s[i] != prv) {
ans++;
prv = s[nxt(i)];
i = nxt(i);
}
}
if(i != st) ans--;
else if(s[st] == prv) ans--;
return ans;
}

int main() {
cin >> s; n = strlen(s);
cout << go() << '\n';
return 0;
}