#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int f=(a+b)%2,fa,fb,fc,fd;
		fa=fb=fc=fd=0;
		if(a>0||d>0) {
			if(f==0)fd=1;
			else fa=1;
		}
		if(b>0||c>0) {
			if(f==0)fc=1;
			else fb=1;
		}
		printf(fa?"Ya ":"Tidak ");
		printf(fb?"Ya ":"Tidak ");
		printf(fc?"Ya ":"Tidak ");
		puts(fd?"Ya":"Tidak");
		
	}
	return 0;
}