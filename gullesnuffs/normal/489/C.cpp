#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char ans[105];

int main(){
	int m, s;
	scanf("%d%d", &m, &s);
	if(s == 0){
		if(m == 1)
			printf("0 0\n");
		else
			printf("-1 -1\n");
		return 0;
	}
	if(s > m*9){
		printf("-1 -1\n");
		return 0;
	}
	int M=s;
	for(int i=0; i < m; ++i){
		int c=M-9*(m-i-1);
		if(c < 0)
			c=0;
		if(c == 0 && i == 0)
			c=1;
		M -= c;
		ans[i]=c+'0';
	}
	ans[m]=0;
	printf("%s", ans);
	M=s;
	for(int i=0; i < m; ++i){
		int c=M;
		if(c > 9)
			c=9;
		M -= c;
		ans[i]=c+'0';
	}
	printf(" %s\n", ans);
}