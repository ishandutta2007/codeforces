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

int main(){
	int n;
	scanf("%d", &n);
	if(n == 1){
		puts("1");
		puts("1");
		return 0;
	}
	if(n == 2){
		puts("1");
		puts("1");
		return 0;
	}
	if(n == 3){
		puts("2");
		puts("1 3");
		return 0;
	}
	if(n == 4){
		puts("4");
		puts("2 4 1 3");
		return 0;
	}
	printf("%d\n", n);
	int mid=(n+1)/2;
	for(int i=0; i < n; ++i){
		if(i%2)
			printf("%d ", mid+(i/2)+1);
		else
			printf("%d ", i/2+1);
	}
	printf("\n");
}