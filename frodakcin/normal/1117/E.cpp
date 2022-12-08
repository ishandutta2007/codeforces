#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e4 + 100;
const int MC = 26;

string A = "abcdefghijklmnopqrstuvwxyz";
#define ti(X) static_cast<int>(X)
inline int ci(char& s) {return ti(s) - 97;}
char s[MN];

int N;
char o[MN], n[MN], f[MN];
int l[MN];

int main() {
	scanf(" %s", s);
	for(N = 0;s[N] != '\0';N++) l[N] = 0;
	
	int x = 1;
	for(int i = 0;i < 3;i++, x *= MC) {
		for(int j = 0, c = 0, d = 0;j < N;j++) {
			o[j] = A[d];
			if(++c == x) c = 0, d++;
			if(d == MC) d = 0;
		}
		o[N] = '\0';
		printf("? %s\n", o);
		fflush(stdout);
		scanf(" %s", n);
		for(int i = 0;i < N;i++) l[i] += ci(n[i]) * x;
	}
	for(int i = 0;i < N;i++) f[l[i]] = s[i];
	
	printf("! %s\n", f);
	
	return 0;
}