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

bool field[1005][1005];

bool check(int x, int y){
	bool ok=1;
	for(int i=0; i < 2; ++i)
		for(int j=0; j < 2; ++j)
			if(field[x+i][y+j] == 0)
				return true;
	return false;
}

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i < k; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		field[a][b]=1;
		for(int j=0; j < 2; ++j)
			for(int k=0; k < 2; ++k)
				if(!check(a-j,b-k)){
					printf("%d\n", i+1);
					return 0;
				}
	}
	printf("0\n");
}