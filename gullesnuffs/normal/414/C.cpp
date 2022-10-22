#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int a[2100000];
int b[2100000];
long long inv[21][2];
bool isInv[21];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < (1<<n); ++i)
		scanf("%d", a+i);
	for(int i=0; i < n; ++i){
		isInv[i]=0;
		for(int j=0; j < (1<<n); j += (2<<i)){
			int p1=0, p2=0;
			int sameN;
			int prevVal=-1;
			for(int k=0; k < (2<<i); ++k){
				if(p2 == (1<<i) || (p1 < (1<<i) && a[j+p1] < a[j+(1<<i)+p2])){
					b[k]=a[j+(p1++)];
					inv[i][0] += p2;
					if(b[k] == prevVal)
						inv[i][0] -= sameN;
				}
				else{
					b[k]=a[j+(1<<i)+(p2++)];
					inv[i][1] += p1;
					if(b[k] == prevVal)
						sameN++;
					else
						sameN=1;
					prevVal=b[k];
				}
			}
			for(int k=0; k < (2<<i); ++k)
				a[j+k]=b[k];
		}
	}
	int m;
	scanf("%d", &m);
	for(int i=0; i < m; ++i){
		int q;
		scanf("%d", &q);
		for(int j=0; j < q; ++j){
			isInv[j]^=1;
		}
		long long sum=0;
		for(int j=0; j < n; ++j){
			sum += inv[j][isInv[j]];
		}
		printf("%I64d\n", sum);
	}
	return 0;
}