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

int p[10];
int n, k;
double ans=0;

void rev(int i, int j){
	for(int k=0; k <= (j-i)/2; ++k)
		swap(p[i+k],p[j-k]);
}
void rec(double prob, int d){
	if(d == 0){
		rep(i,0,n)
			rep(j,i+1,n){
				if(p[j] < p[i])
					ans += prob;
			}
		return;
	}
	int sum=0;
	rep(i,0,n)
		rep(j,i,n)
			++sum;
	rep(i,0,n)
		rep(j,i,n){
			rev(i,j);
			rec(prob/sum,d-1);
			rev(i,j);
		}
}

int main(){
	scanf("%d%d", &n, &k);
	rep(i,0,n)
		scanf("%d", p+i);
	rec(1,k);
	printf("%.10lf\n", ans);
}