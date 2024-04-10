#include <bits/stdc++.h>

using namespace std;

int x[8],y[8];

int cross(int p1, int p2, int p3){
	return x[p1]*y[p2]-x[p2]*y[p1]+x[p2]*y[p3]-x[p3]*y[p2]+x[p3]*y[p1]-x[p1]*y[p3];
}

int dot(int p1, int p2, int p3){
	return (x[p1]-x[p2])*(x[p3]-x[p2])+(y[p1]-y[p2])*(y[p3]-y[p2]);
}

int len(int p1, int p2){
	int dx=x[p1]-x[p2], dy=y[p1]-y[p2];
	return dx*dx+dy*dy;
}

bool isRectangle(int p1, int p2, int p3, int p4){
	if(dot(p1,p2,p3)||dot(p2,p3,p4)||dot(p3,p4,p1)||dot(p4,p1,p2))
		return 0;
	return 1;
}

bool isSquare(int p1, int p2, int p3, int p4){
	if(len(p2,p3)!=len(p1,p2))
		return 0;
	if(len(p4,p3)!=len(p1,p2))
		return 0;
	if(len(p4,p1)!=len(p1,p2))
		return 0;
	if(!isRectangle(p1,p2,p3,p4))
		return 0;
	return 1;
}

int main(){
	for(int i=0; i < 8; ++i)
		scanf("%d%d", x+i, y+i);
	int p[8];
	iota(p, p+8, 0);
	do{
		if(isSquare(p[0],p[1],p[2],p[3]) && isRectangle(p[4],p[5],p[6],p[7])){
			puts("YES");
			printf("%d %d %d %d\n", p[0]+1,p[1]+1,p[2]+1,p[3]+1);
			printf("%d %d %d %d\n", p[4]+1, p[5]+1, p[6]+1, p[7]+1);
			return 0;
		}
	}
	while(next_permutation(p, p+8));
	puts("NO");
}