//ok test done
//so actually must do offline
//good to know

#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 1000005
using namespace std;


struct dat{
	int x, y, id;
	bool operator < (dat const &T) const{return y < T.y;}
};


int n, m, t, ptr;
int stack[N], ret[100005], B[N];
char s[N];
dat q[100005];

int main(){
	scanf("%s", s);
	n = strlen(s);
	scanf("%d", &m);
	FOR(i,0,m) scanf("%d%d", &q[i].x, &q[i].y), q[i].id = i;
	sort(q, q + m);
	
	FOR(i,0,n){
		if (s[i] == '('){
			stack[t++] = i;
		}
		else if (t > 0){
			--t;
		    for (int j=stack[t]+1; j>=1; j-=j&-j) ++B[j];
		}
		while (ptr < m && q[ptr].y == i + 1){
			for (int j=q[ptr].x; j<=n; j+=j&-j) ret[q[ptr].id] += B[j];
			++ptr;
		}
	}
	
	FOR(i,0,m) printf("%d\n", ret[i] << 1);
	return 0;
}