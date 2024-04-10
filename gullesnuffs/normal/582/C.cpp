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

int n;
int a[200005];
int M[200005];
bool good[200005];
int consec[200005];
int score[200005];

int gcd(int x, int y){
	return y?gcd(y, x%y):x;
}

ll calc(int d){
	rep(i,0,d)
		M[i]=0;
	rep(i,0,n){
		M[i%d]=max(M[i%d], a[i]);
	}
	int bad=0;
	rep(i,0,d){
		bad += (a[i] < M[i%d]);
	}
	ll ret=0;
	rep(i,0,n){
		good[i]=(bad == 0);
		bad -= (a[i] < M[i%d]);
		bad += (a[(i+d)%n] < M[i%d]);
		consec[i]=0;
	}
	rep(i,0,n){
		if(good[i])
			consec[i]=1+consec[(i+n-d)%n];
	}
	score[0]=0;
	rep(i,1,n/d+1){
		score[i]=score[i-1];
		if(gcd(i, n/d) == 1)
			++score[i];
	}
	rep(i,0,n){
		if(good[i]){
			consec[i]=1+consec[(i+n-d)%n];
			if(consec[i] >= n/d){
				ret += score[n/d];
			}
			else
				ret += score[consec[i]];
		}
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
	}
	ll ans=0;
	rep(i,1,n){
		if(n%i == 0)
			ans += calc(i);
	}
	printf("%I64d\n", ans);
}