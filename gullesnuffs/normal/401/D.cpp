#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Digits{
	int d[10];
	int M;
	bool operator<(const Digits &other) const{
		for(int i=0; i < 10; ++i){
			if(d[i] != other.d[i])
				return d[i]<other.d[i];
		}
		return M < other.M;
	}
};

int modulo[25];
map<Digits, long long> dp[25];
int D[10];

int main(){
	long long n;
	int m;
	scanf("%I64d%d", &n, &m);
	int s=0;
	while(n){
		D[n%10]++;
		++s;
		n/=10;
	}
	modulo[0]=1%m;
	for(int i=1; i <= 20; ++i){
		modulo[i]=(10*modulo[i-1])%m;
	}
	for(int i=1; i < 10; ++i)
		if(D[i]){
			Digits digits;
			for(int j=0; j < 10; ++j)digits.d[j]=0;
			digits.d[i]=1;
			digits.M=(modulo[s-1]*i)%m;
			dp[1][digits]=1;
		}
	for(int i=2; i <= s; ++i){
		for(auto it = dp[i-1].begin(); it != dp[i-1].end(); ++it){
			for(int j=0; j < 10; ++j){
				if(it->first.d[j] < D[j]){
					Digits newDigits;
					for(int k=0; k < 10; ++k)
						newDigits.d[k]=it->first.d[k];
					newDigits.d[j]++;
					newDigits.M=(it->first.M+j*modulo[s-i])%m;
					dp[i][newDigits] += it->second;
				}
			}
		}
	}
	Digits ansDigits;
	for(int i=0; i < 10; ++i)
		ansDigits.d[i]=D[i];
	ansDigits.M=0;
	printf("%I64d\n", dp[s][ansDigits]);
	return 0;
}