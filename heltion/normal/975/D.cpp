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
struct gh{
	long long x, v_x, v_y;
	long long p;
	bool operator < (const gh &rhs){
		if(p != rhs.p) return p < rhs.p;
		return v_x < rhs.v_x;
	}
};
int main(){
	long long n = read(), a = read(), b = read();
	gh *G = new gh [n];
	for(int i = 0; i < n; i += 1){
		G[i].x = read();
		G[i].v_x = read();
		G[i].v_y = read();
		G[i].p = G[i].v_y - a * G[i].v_x;
	}
	sort(G, G + n);
	int L = 0, R = 0;
	long long ans = 0;
	while(L < n){
		while(R < n and G[R].p == G[L].p) R += 1;
		vector<int> v;
		for(int i = L; i < R; i += 1){
			if(i == L or G[i].v_x != G[i - 1].v_x) v.push_back(1);
			else v[v.size() - 1] += 1;
		}
		long long sum = 0, psum = 0;
		for(int &i: v){
			sum += i;
			psum += (long long)i * i;
		}
		ans += ((sum * sum) - psum) / 2;
		L = R;
	}
	printf("%lld", ans * 2);
}