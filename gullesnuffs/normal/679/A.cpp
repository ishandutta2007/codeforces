#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int primes[100];
int primeN=0;

bool isPrime(int x){
	for(int i=2; i*i <= x; ++i)
		if(x%i == 0)
			return 0;
	return 1;
}

int main(){
	int numPrimes=0;
	rep(p,2,51){
		if(!isPrime(p))
			continue;
		printf("%d\n", p);
		fflush(stdout);
		char answer[20];
		scanf("%s", answer);
		if(answer[0] == 'y'){
			++numPrimes;
			if(p*p < 100){
			printf("%d\n", p*p);
			fflush(stdout);
			scanf("%s", answer);
			if(answer[0] == 'y'){
				++numPrimes;
			}
			}
		}
		else{
		}
	}
	if(numPrimes >= 2)
		printf("composite\n");
	else
		printf("prime\n");
	fflush(stdout);
}