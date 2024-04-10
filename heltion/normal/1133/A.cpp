#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
void no(){cout << "NO"; exit(0);}
int main(){
	int h1, m1, h2, m2;
	scanf("%d:%d\n%d:%d", &h1, &m1, &h2, &m2);
	int h3 = 0, m3 = (h1 * 60 + h2 * 60 + m1 + m2) / 2;
	h3 += m3 / 60; m3 %= 60;
	printf("%02d:%02d", h3, m3);
}