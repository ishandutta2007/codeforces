#include<iostream>
#include<cstdio>

using namespace std;


int main() {
	int h1, h2, m1, m2;
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	h1 -= h2;
	m1 -= m2;
	if(m1 < 0) m1 += 60, h1--;
	if(h1 < 0) h1 += 24;
	printf("%d%d:%d%d\n", h1 / 10, h1 % 10, m1 / 10, m1 % 10);
	return 0;
}