#include <bits/stdc++.h>

using namespace std;

int l[4];

bool triangle(int a, int b, int c){
	int m=max(max(a,b),c)*2;
	if(m >= (a+b+c))
		return 0;
	return 1;
}
bool segment(int a, int b, int c){
	int m=max(max(a,b),c)*2;
	if(m > (a+b+c))
		return 0;
	return 1;
}

int main(){
	for(int i=0; i < 4; ++i)
		scanf("%d", l+i);
	for(int i=0; i < 4; ++i){
		int p=0;
		int b[3];
		for(int j=0; j < 4; ++j)
			if(i != j)
				b[p++]=j;
		if(triangle(l[b[0]],l[b[1]],l[b[2]])){
			puts("TRIANGLE");
			return 0;
		}
	}
	for(int i=0; i < 4; ++i){
		int p=0;
		int b[3];
		for(int j=0; j < 4; ++j)
			if(i != j)
				b[p++]=j;
		if(segment(l[b[0]],l[b[1]],l[b[2]])){
			puts("SEGMENT");
			return 0;
		}
	}
	puts("IMPOSSIBLE");
}