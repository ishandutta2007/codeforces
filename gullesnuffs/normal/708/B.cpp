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

int a[2][2];

int getN(int A){
	for(ll n=1; n < 100000; ++n){
		if((n*(n-1))/2 == A)
			return n;
	}
	return -1;
}

int main(){
	rep(i,0,2)
	rep(j,0,2)
		scanf("%d", a[i]+j);
	if(!a[0][0]){
		if(!a[0][1] && !a[1][0] && a[1][1]){
			int n=getN(a[1][1]);
			if(n == -1){
				puts("Impossible");
			}
			else{
			rep(i,0,n)
				printf("1");
			printf("\n");
			}
			return 0;
		}
		else{
			/*puts("Impossible");
			return 0;*/
		}
	}
	if(!a[1][1]){
		if(!a[0][1] && !a[1][0] && a[0][0]){
			int n=getN(a[0][0]);
			if(n == -1)puts("Impossible");
			else{
			rep(i,0,n)
				printf("0");
			printf("\n");
			}
			return 0;
		}
		else{
			/*puts("Impossible");
			return 0;*/
		}
	}
	int n[2];
	n[0]=getN(a[0][0]);
	n[1]=getN(a[1][1]);
	if(n[0] == -1 || n[1] == -1){
		puts("Impossible");
		return 0;
	}
	if(a[0][1]+a[1][0] != n[0]*n[1]){
		if(a[0][0] == 0 && a[0][1] == 0 && !a[1][0] && !a[1][1]){
			printf("0\n");
			return 0;
		}
		puts("Impossible");
		return 0;
	}
	while(a[0][1] >= n[1]){
		printf("0");
		--n[0];
		a[0][1] -= n[1];
	}
	rep(i,0,n[1]-a[0][1])
		printf("1");
	if(n[0]){
		--n[0];
		printf("0");
	}
	rep(i,0,a[0][1])
		printf("1");
	while(n[0]){
		printf("0");
		--n[0];
	}
	printf("\n");
}