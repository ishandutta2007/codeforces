#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		b[i]=a[i];
	}
	sort(b, b+n);
	for(int i=0; i < n; ++i){
		if(a[i] != b[i]){
			bool ok=1;
			int j;
			for(j=i+1; j < n; ++j){
				if(a[j] == b[i])
					break;
			}
			for(int k=0; k <= j-i; ++k)
				if(a[i+k] != b[j-k])
					ok=0;
			for(int k=j+1; k < n; ++k)
				if(a[k] != b[k])
					ok=0;
			if(!ok){
				puts("no");
				return 0;
			}
			else{
				printf("yes\n%d %d\n", i+1, j+1);
				return 0;
			}
		}
	}
	printf("yes\n1 1\n");

}