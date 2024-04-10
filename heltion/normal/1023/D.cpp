#include<bits/stdc++.h>
#define maxn 240000 
using namespace std;
int L[maxn], R[maxn];
int a[maxn], t[maxn];
int tag[maxn << 2];
void push_down(int o){
	if(tag[o]){
		tag[o * 2] = tag[o];
		tag[o * 2 + 1] = tag[o];
	}
	tag[o] = 0;
}
void modify(int o, int l, int r, int L, int R, int q){
	if(l >= L && r <= R) tag[o] = q;
	else{
		push_down(o);
		int m = (l + r) / 2;
		if(L <= m) modify(o * 2, l, m, L, R, q);
		if(R > m) modify(o * 2 + 1, m + 1, r, L, R, q);
	}
}
void gett(int o, int l, int r){
	if(l == r) t[l] = tag[o];
	else{
		push_down(o);
		int m = (l + r) / 2;
		gett(o * 2, l, m);
		gett(o * 2 + 1, m + 1, r);
	}
}
int main(){
	int n, q;
	scanf("%d %d", &n ,&q);
	for(int i = 1; i <= n; i += 1) scanf("%d", a + i);
	for(int i = 1; i <= n; i += 1){
		if(L[a[i]] == 0) L[a[i]] = i;
		R[a[i]] = i;
	}
	if(L[q] == 0){
		for(int i = 1; i <= n; i += 1) if(a[i] == 0){
			a[i] = q;
			L[q] = R[q] = i;
			break;
		}
	}
	for(int i = 1; i <= q; i += 1)
		if(L[i]) modify(1, 1, n, L[i], R[i], i);
	gett(1, 1, n);
//	for(int i = 1; i <= q; i += 1){
//		printf("%d %d\n", L[i], R[i]);
//	}
//	for(int i = 1; i <= n; i += 1){
//		printf("%d ", t[i]);
//	}printf("\n");
	bool flag = true;
	int zero = 0;
	for(int i = 1; i <= n; i += 1){
		if(a[i] && t[i] != a[i]) flag = false;
		if(t[i] == 0) zero += 1;
	}
	if(flag == false || zero == 0 && L[q] == 0){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	if(L[q]){
		for(int i = 2; i <= n; i += 1) if(t[i] == 0) t[i] = t[i - 1]; 
		for(int i = n - 1; i >= 1; i -= 1) if(t[i] == 0) t[i] = t[i + 1];
	}
	else{
		for(int i = 1; i <= n; i += 1){
			if(t[i] == 0){
				t[i] = q;
				break;
			}
		}
		for(int i = 2; i <= n; i += 1) if(t[i] == 0) t[i] = t[i - 1]; 
		for(int i = n - 1; i >= 1; i -= 1) if(t[i] == 0) t[i] = t[i + 1];
	}
	for(int i = 1; i <= n; i += 1){
		printf("%d ", t[i]);
	}
}