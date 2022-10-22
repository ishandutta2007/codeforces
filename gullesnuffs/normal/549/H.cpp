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

double a,b,c,d;
int s[4];
ll A,B,C,D;

int main(){
	scanf("%I64d%I64d%I64d%I64d", &A, &B, &C, &D);
	if(A*D == B*C){
		puts("0");
		return 0;
	}
	a=A;b=B;c=C;d=D;
	double ans=1000000000;
	for(int i=0; i < 16; ++i){
		for(int j=0; j < 4; ++j){
			if(i&(1<<j))
				s[j]=1;
			else
				s[j]=-1;
		}
		double e=s[0]*s[3]-s[1]*s[2];
		double f=a*s[3]+d*s[0]-b*s[2]-c*s[1];
		double g=a*d-b*c;
		if(e != 0){
			f/=e;
			g/=e;
			if(f*f/4-g < 0)
				continue;
			ans=min(ans, abs(-f/2+sqrt(f*f/4-g)));
			ans=min(ans, abs(-f/2-sqrt(f*f/4-g)));
		}
		else if(f != 0){
			ans=min(ans, abs(g/f));
		}
	}
	printf("%.10lf\n", ans);
}