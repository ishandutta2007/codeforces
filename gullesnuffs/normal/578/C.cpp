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

int a[200005];
double A[200005];
double cum[200005];
int n;
double lo, hi;

void calc(){
	cum[0]=0;
	double l=0, h=0;
	lo=0, hi=0;
	rep(i,0,n){
		cum[i+1]=cum[i]+A[i];
		double c=cum[i+1];
		l=min(l,c);
		h=max(h,c);
		lo=min(lo,c-h);
		hi=max(hi,c-l);
	}
}

int main(){
	scanf("%d", &n);
	rep(i,0,n)
		scanf("%d", a+i);
	double lx=-10000, hx=10000;
	rep(i,0,60){
		double mid=(lx+hx)/2;
		rep(j,0,n)
			A[j]=a[j]-mid;
		calc();
		if(hi > -lo)
			lx=mid;
		else
			hx=mid;
	}
	printf("%.9lf\n", hi);
}