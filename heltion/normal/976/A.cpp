#include<bits/stdc++.h>
using namespace std;
int read(){
	int x = 0;
	char c;
	bool pos = true;
	do{
		c = getchar();
		if(c == '-') pos = false;
	}while(c < '0' or c > '9');
	do{
		x = x * 10 + c - '0';
		c = getchar();
	}while(c >= '0'  and c <= '9');
	return pos ? x : - x;
}
int main(){
	int n = read();
	char *s = new char [n + 1];
	scanf("%s", s);
	int c = 0;
	for(int i = 0; i < n; i += 1)if(s[i] == '0') c += 1;
	if(c == n) printf("0\n");
	else{
		printf("1");
		for(int i = 0; i < c; i += 1) printf("0");
	}
}