#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x = 0;
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
struct segment{
	int l, r, id;
	bool operator < (const segment &rhs){
		if(l != rhs.l) return l < rhs.l;
		return r > rhs.r;
	}
}; 
int main(){
	int n = read();
	segment *S = new segment[n];
	for(int i = 0; i < n; i += 1){
		S[i].l = read();
		S[i].r = read();
		S[i].id = i + 1;
	}
	sort(S, S + n);
	int *D = new int[n];
	D[0] = 0;
	for(int i = 1; i < n; i += 1){
		if(S[i].r >= S[D[i - 1]].r) D[i] = i;
		else D[i] = D[i - 1];
	}
	for(int i = 1; i < n; i += 1)
		if(S[i].r <= S[D[i - 1]].r){
			printf("%d %d", S[i].id, S[D[i - 1]].id);
			return 0;
		}
	printf("-1 -1");
}