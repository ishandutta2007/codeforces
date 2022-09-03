#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int main() {
	LL k;
	scanf("%lld",&k);
	for(LL i = 1;;i++){
		if(i*i*i*i*i*i*i*i*i*i>=k){
			LL val=i*i*i*i*i*i*i*i*i*i;
			int cnt=0;
			while(val/i*(i-1)>=k){
				cnt++;
				val=val/i*(i-1);
			}
			char c[15]="codeforces";
			for(int j=0;j<cnt;j++){
				for(int k = 1;k<i;k++){
					printf("%c",c[j]);
				}
			}
			
			for(int j=cnt;j<10;j++){
				for(int k = 0;k<i;k++){
					printf("%c",c[j]);
				}
			}
			printf("\n");
			break;
		}
	}
	return 0;
}