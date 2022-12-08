#include<bits/stdc++.h>
using namespace std;
struct mat {
	int x0,x1,y0,y1;
	void read() {
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
	}
} a,b1,b2;
int in(mat a,mat b) {
	return a.x0<=b.x0&&b.x1<=a.x1&&a.y0<=b.y0&&b.y1<=a.y1;
}
int main() {
	a.read();
	b1.read();
	b2.read();
	if(in(b1,a)||in(b2,a)) {
		puts("NO");
		return 0;
	}
	if(b1.x0<=a.x0&&b1.x1>=a.x1) {
		if(b1.y1<a.y1&&b1.y0<=a.y0)a.y0=b1.y1;
		else if(b1.y0>a.y0&&b1.y1>=a.y1)a.y1=b1.y0;
		puts(in(b2,a)?"NO":"YES");
		return 0;
	}
	if(b1.y0<=a.y0&&b1.y1>=a.y1) {
		if(b1.x1<a.x1&&b1.x0<=a.x0)a.x0=b1.x1;
		else if(b1.x0>a.x0&&b1.x1>=a.x1)a.x1=b1.x0;
		puts(in(b2,a)?"NO":"YES");
		return 0;
	}
	puts("YES");
	return 0;
}