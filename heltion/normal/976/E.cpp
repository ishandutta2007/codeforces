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
struct creature{
	long long hp, dmg;
	bool operator < (const creature &rhs){
		return hp - dmg > rhs.hp - rhs.dmg;
	}
};
int main(){
	int n = read(), a = read(), b = read();
	b = min(n, b);
	creature *C = new creature [n];
	long long ansb = 0;
	long long *S = new long long [n];
	for(int i = 0; i < n; i += 1){
		C[i].hp = read();
		C[i].dmg = read();
		ansb += C[i].dmg;
	}
	if(b == 0){
		printf("%lld", ansb);
		return 0;
	}
	sort(C, C + n);
	for(int  i = 0; i < n; i += 1){
		if(i) S[i] = S[i - 1] + max(C[i].hp - C[i].dmg, 0LL);
		else S[i] = max(C[i].hp - C[i].dmg, 0LL);
	}
	long long ansa = 0;
	for(int i = 0; i < n; i += 1){
		if(i < b){
			if(C[i].hp > C[i].dmg){
				ansa = max(ansa, S[b - 1] + (C[i].hp << a) - C[i].hp);
			}
			else{
				ansa = max(ansa, S[b - 1] + (C[i].hp << a) - C[i].dmg);
			}
		}
		else{
			ansa = max(ansa, (b >= 2 ? S[b - 2] : 0)+ (C[i].hp << a) - C[i].dmg);
		}
		
	}
	printf("%lld", ansa + ansb);
}