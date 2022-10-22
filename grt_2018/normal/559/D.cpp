#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define DET(a,b,c) ((ll)(b-a).x*(c-a).y-(ll)(b-a).y*(c-a).x)
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
 
struct Point {
	int x,y;
	Point operator - (Point pp) {
		return {x-pp.x,y-pp.y};
	}
};
 
const int nax = 100*1000+10;
int n;
Point p[nax],P;
long double eArea,ePoint;
 
long double add_fraction(int k) {
	if(n<=62) {
		long double x = (long double)(((ll)1<<k)-1)/(((ll)1<<n)-1-n-(ll)n*(n-1)/2);
		//cout<<x<<"\n";
		return x;
	} else {
		//if(n>k+62) return 0;
		long double x = (long double)1/(((ll)1<<(k+2)));
		//cout<<x<<"\n";
		return x;
	}
}
 
void calc_eArea() {
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=min(i+62,n+i-1); j++) {
			int jj=(j%n==0)?n:j%n,k = j-i-1, A = p[i].y-p[jj].y, B = p[jj].x-p[i].x,g,cnt;
			eArea+=add_fraction(k)*DET(P,p[i],p[jj]);
			//eArea+=add_fraction(n-k-2)*DET(P,p[jj],p[i]);
			g = __gcd(abs(A),abs(B));
			//cout<<i<<" "<<j<<" "<<A<<" "<<B<<" "<<g<<"\n";
			ePoint+=add_fraction(k)*g;
			//ePoint+=add_fraction(n-k-2)*cnt;
		}
	}
}
 
int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>p[i].x>>p[i].y;
	}
	P = {0,0};
	calc_eArea();
	eArea = fabs(eArea)/2.0;
	//cout<<setprecision(10)<<eArea<<"\n";
	//cout<<setprecision(10)<<ePoint<<"\n";
	long double ans = eArea+1-ePoint/2.0;
	cout<<fixed;
	cout<<setprecision(20)<<ans<<"\n";
}