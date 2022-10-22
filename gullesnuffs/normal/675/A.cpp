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
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(c < 0){
		a=-a;
		b=-b;
		c=-c;
	}
	if(b < a)
		puts("NO");
	else if(!c)
		puts(a == b?"YES":"NO");
	else
		puts(((b-a)%c)?"NO":"YES");
}