#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
template <class T>
struct Point 
{
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-* this).cross(b-* this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to xaxis in interval [pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return * this/dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated a  radians ccw around the origin
    P rotate(double a) const { return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
typedef Point<double> P;
template <class P>
double lineDist(const P& a, const P& b, const P& p) 
{
    return (double)(b-a).cross(p-a)/(b-a).dist();
}
int sideOf(const P& s, const P& e, const P& p) {
    auto a = (e-s).cross(p-s);
    return (a > 0) - (a < 0);
}
void solve()
{
	int n;
	cin>>n;
	vector<P> v(n);;
	rep(i,0,n){
		cin>>v[i].x>>v[i].y;
	}
	double ans=0;
	rep(i,0,n){
		rep(j,i+1,n){
			double h1=-1,h2=-1;
			rep(k,0,n){
				if(k==i || k==j) continue;
				if(sideOf(v[i],v[j],v[k])==-1){
					h1=max(h1,abs(lineDist(v[i],v[j],v[k])));
				}
				else{
					h2=max(h2,abs(lineDist(v[i],v[j],v[k])));
				}
			}
			if(h1>=0 && h2>=0)
			ans=max(ans,(v[i]-v[j]).dist()*(h1+h2)/2);
		}
	}
	cout<<fixed<<setprecision(14);
	cout<<ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}