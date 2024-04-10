#include<bits/stdc++.h>
#define maxn 1200
using namespace std;
typedef long long LL;
int p[maxn];
bool vis[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1) scanf("%d", p + i);
	for(int i = 1; i <= n; i += 1){
		for(int j = 1; j <= n; j += 1) vis[j] = false;
		int a = i;
		while(vis[a] == false){
			vis[a] = true;
			a = p[a];
		}
		printf("%d ", a);
	}
}