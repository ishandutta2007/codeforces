#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 5050;
int N;
char s[MN], z;
bool w;

bool edge() {
	z = s[0];
	for(int i = 1;i < N>>1;i++) if(z != s[i]) return 0;
	return printf("Impossible\n"), 1;
}
int sum(int a, int b) {return (a+b)%N;}
int dif(int a, int b) {return (a-b+(N<<2))%N;}
bool test(int C) {
	int H = N>>1;
	bool w = false;
	for(int i = 0;i < H;i++) {
		if(s[sum(C, i+1)] != s[dif(C, i)]) return false;
		if(s[sum(C, i+1)] != s[i]) w = true;
	}
	return w;
}

int main() {
	scanf("%s", s);
	z = s[0], w = false;
	for(N = 0;s[N] != '\0';N++);
	if(edge()) return 0;
	for(int i = 0;i < N;i++) if(test(i)) return printf("1\n"), 0;
	printf("2\n");
	
	return 0;
}