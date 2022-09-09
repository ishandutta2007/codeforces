#include<cstdio>
#define maxn 1000
int h[maxn];
int main(){
	int n, k, a;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n and k; i += 1){
		scanf("%d", &a);
		if(h[a] == 0) h[a] = i, k -= 1;
	}
	if(k) printf("NO");
	else{
		printf("YES\n");
		for(int i = 1; i <= 100; i += 1)
			if(h[i]) printf("%d ", h[i]);
	}
}