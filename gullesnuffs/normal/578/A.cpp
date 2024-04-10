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
	int a, b;
	scanf("%d%d", &a, &b);
	if(a < b){puts("-1");return 0;}
	if(a == b){printf("%d\n", b);return 0;}
	int n=((int)(double(a)/double(b)-1))/2;
	double x1=double(a+b)/(2*(n+1));
	double x2=double(a-b)/(2*n);
	printf("%.9lf\n", min(x1, x2));
	//printf("%.9lf\n", (a+b)/(4.0*(((int)(((double(a)/double(b)-1)))/2))));
}