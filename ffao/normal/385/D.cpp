//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;
const ll mod =1e9+7;
const int maxn = 2000005;
#define endl '\n'
#define int ll
#define ld long double
#define all(x) (x).begin(),(x).end()
 
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
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
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
int32_t main()
{ 
  IOS
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n;
  ld l,r;
  cin>>n>>l>>r;
  ld x[n],y[n],a[n];
  ld PI = acos(-1);
  for(int i = 0;i<n;i++){
    cin>>x[i]>>y[i]>>a[i];
    a[i] *= PI/180.0;
  }
  int total = (1<<n);
  ld dp[total];
  for(int i = 0;i<total;i++) dp[i] = l;
  dp[0] = l;
  for(int m = 0;m<total;m++){
    for(int j = 0;j<n;j++){
      if((m>>j)&1) continue;
      Point<ld> p(dp[m] - x[j],0.0 - y[j]);
      
      if(y[j]>0){
        p  = p.rotate(a[j]);
      }
      else{
        p  = p.rotate(-a[j]);
      }
      p= p+ Point<ld>(x[j],y[j]);
      ld nx = ((x[j] - p.x)/(y[j] - p.y) )* (-p.y) + p.x;
      if(nx<dp[m]){
        dp[total-1] = r;
        goto fd;
      }
      dp[m|(1<<j)] = max(nx,dp[m|(1<<j)]);
    }
  }
  fd:;
  cout<<setprecision(15)<<fixed;
  cout<<min(r-l,dp[total-1]-l)<<endl;
  
 
}