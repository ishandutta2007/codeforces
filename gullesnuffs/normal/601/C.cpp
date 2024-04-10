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

int pos[105];
double prob[105][110005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int sum=0;
	rep(i,0,n){
		scanf("%d", pos+i);
		sum += pos[i];
	}
	if(m == 1){
		printf("1.000000000\n");
		return 0;
	}
	prob[0][0]=1;
	rep(i,0,n){
		double cumsum=0;
		double mult=1;
		mult /= m-1;
		rep(j,0,((i+1)*m)+2){
			cumsum += prob[i][j];
			if(j >= m)
				cumsum -= prob[i][j-m];
			prob[i+1][j+1]=cumsum;
			if(j+1-pos[i] >= 0)
				prob[i+1][j+1] -= prob[i][j+1-pos[i]];
			prob[i+1][j+1] *= mult;
		}
	}
	double probwin=0;
	rep(j,0,sum)
		probwin += prob[n][j];
	double ans=1+probwin*(m-1);
	printf("%.10lf\n", ans);
}