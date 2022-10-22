#include <bits/stdc++.h>
using namespace std;
int main(){
	int w, h, w1, h1, w2, h2;
	scanf("%d%d%d%d%d%d", &w, &h, &w1, &h1, &w2, &h2);
	while (h){
		w += h;
		if (h == h1) w -= w1;
		if (h == h2) w -= w2;
		if (w < 0) w = 0;
		h--;
	}
	printf("%d\n", w);
	return 0;
}