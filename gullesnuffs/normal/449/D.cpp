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
#include <cassert>
#define MAXA (1<<20)
#define MOD 1000000007
using namespace std;

int has[MAXA];
int combo[MAXA+1];
int pot[MAXA];

int main(){
	pot[0]=1;
	for(int i=1; i < MAXA; ++i)
		pot[i]=(pot[i-1]*2)%MOD;
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		++has[a];
		++combo[a];
	}
	for(int i=1; i < MAXA; i*=2){
		for(int j=0; j < MAXA; ++j){
			if(j&i)
				j += i;
			combo[j] += combo[j+i];
		}
	}
	/*for(int i=0; i < MAXA; ++i){
		for(int j=i; j >= 0; j=(i&(j-1))){
			combo[j] += has[i];
			if(!j)
				break;
		}
	}*/
	long long ans=0;
	for(int i=0; i < MAXA; ++i){
		int cnt=__builtin_popcount(i);
		int s=(cnt%2?-1:1);
		ans += pot[combo[i]]*s;
		ans%=MOD;
		while(ans < 0)
			ans += MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}