#include<bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
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
	long long n = read(), m = read(), cl = read(), ce = read(), v = read();
	
	long long *l = new long long [cl];
	
	long long *e = new long long [ce];
	
	for(int i = 0; i < cl; i += 1) l[i] = read();
	
	for(int i = 0; i < ce; i += 1) e[i] = read();
	
	for(int q = read(); q; q -= 1){
		
		long long x1 = read(), y1 = read(), x2 = read(), y2 = read();
		
		if(x1 == x2){
			 printf("%lld\n", abs(y1 - y2));
			 continue;
		}
		
		if(y1 > y2) swap(y1, y2);
		
		long long ansl = INF;
		
		int pos = lower_bound(l, l + cl, y1) - l;
		if(cl){
			if(pos == cl) ansl = y2 + y1 - 2 * l[cl - 1] + abs(x1 - x2);
		
			else{
			
				if(l[pos] <= y2) ansl = y2 - y1 + abs(x1 - x2);
				else {
					ansl = 2 * l[pos] - y1 - y2 + abs(x1 - x2);
					if(pos) ansl = min(ansl, y2 + y1 - 2 * l[pos - 1] + abs(x1 - x2));
				}
			}
		}
		
		
		long long anse = INF;
		
		pos = lower_bound(e, e + ce, y1) - e;
		
		if(ce){
			if(pos == ce) anse = y2 + y1 - 2 * e[ce - 1] + (abs(x1 - x2) % v == 0 ? abs(x1 - x2) / v : abs(x1 - x2) / v + 1);
		
			else{
			
				if(e[pos] <= y2) anse = y2 - y1 + (abs(x1 - x2) % v == 0 ? abs(x1 - x2) / v : abs(x1 - x2) / v + 1);
				else{
					anse = 2 * e[pos] - y1 - y2 + (abs(x1 - x2) % v == 0 ? abs(x1 - x2) / v : abs(x1 - x2) / v + 1);
					if(pos) anse = min(anse, y2 + y1 - 2 * e[pos - 1] + (abs(x1 - x2) % v == 0 ? abs(x1 - x2) / v : abs(x1 - x2) / v + 1));
				}
			}
		}
		
		
		printf("%lld\n", anse < ansl ? anse : ansl);
	}
}

//long long?10 ^18int?10^9