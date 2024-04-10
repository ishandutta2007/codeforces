#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a[2],b[2],c[2];
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",a+0,a+1,b+0,b+1,c+0,c+1);
	long long cross=a[0]*b[1]-a[1]*b[0]+b[0]*c[1]-b[1]*c[0]+c[0]*a[1]-a[0]*c[1];
	if(cross < 0)
		puts("RIGHT");
	else if(cross > 0)
		puts("LEFT");
	else
		puts("TOWARDS");
}