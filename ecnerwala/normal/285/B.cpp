#include<iostream>
#include<cstring>

using namespace std;

int go() {
	int n, s, t, p[100005];
	cin >> n >> s >> t; s--, t--;
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) p[i] --;
	bool reached[100005];
	memset(reached, false, sizeof(reached));
	for(int i = 0; i < n; i++) {
if(reached[s]) return -1;
reached[s] = true;
if(s == t) return i;
s = p[s];
}
}

int main() {
cout << go() << '\n';
return 0;
}