#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

bool check(LL tx, LL ty, LL cx, LL cy) {
	LL dx=cy, dy=-cx;
	if(cx==0 && cy==0) return tx==0 && ty==0;
	// need:
	// a cx + b dx = tx
	// a cy + b dy = ty
	// cx cy a + dx cy b = tx cy
	// cx cy a + cx dy b = cx ty
	// (dx cy - cx dy) b = tx cy - cx ty
	// a cx dy + b dx dy = tx dy
	// a dx cy + b dx dy = dx ty
	LL b = (tx*cy-cx*ty) / (dx*cy-cx*dy);
	LL a = (tx*dy-dx*ty) / (cx*dy-dx*cy);
	if(a*cx+b*dx!=tx) return false;
	if(a*cy+b*dy!=ty) return false;
	return true;
}

int main() {
	int ax, ay, bx, by, cx, cy;
	scanf("%d%d%d%d%d%d", &ax,&ay, &bx,&by, &cx, &cy);
	bool flag=false;
	for(int t=0; t<4; ++t) {
		if(check(bx-ax, by-ay, cx, cy)) flag=true;
		int tmp=ax; ax=-ay; ay=tmp;
	}
	printf("%s\n", flag?"YES":"NO");
	return 0;
}