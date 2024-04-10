#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[100005];
int tree[20][1100005];
map<int, long long> M;

int gcd(int x, int y){
	return y?gcd(y, x%y):x;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		tree[0][i]=a[i];
	}
	for(int i=1; i < 20; ++i){
		for(int j=0; j < n; j += (1<<i)){
			tree[i][j]=gcd(tree[i-1][j], tree[i-1][j+(1<<(i-1))]);
			if(!tree[i-1][j+(1<<(i-1))])
				tree[i][j]=0;
		}
	}
	for(int i=0; i < n; ++i){
		int g=a[i];
		int j=i;
		while(j < n){
			g=gcd(g, a[j]);
			int k;
			for(k=0; j%(1<<k) == 0; ++k){
				if(!tree[k][j] || gcd(g, tree[k][j]) != g)
					break;
			}
			--k;
			M[g] += (1<<k);
			j += (1<<k);
		}
	}
	int q;
	scanf("%d", &q);
	for(int i=0; i < q; ++i){
		int x;
		scanf("%d", &x);
		printf("%I64d\n", M[x]);
	}
}