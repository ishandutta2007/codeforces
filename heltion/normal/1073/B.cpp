#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
bool v[maxn];
int a[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1) scanf("%d", a + i);
	int top = 0;
	for(int i = 0; i < n; i += 1){
		int b;
		scanf("%d", &b);
		if(v[b] == true) printf("0 ");
		else{
			int ans = 0;
			while(a[top] != b){
				v[a[top]] = true;
				top += 1;
				ans += 1;
			}
			v[a[top]] = true;
			top += 1;
			ans += 1;
			printf("%d ", ans);
		}
	}
}