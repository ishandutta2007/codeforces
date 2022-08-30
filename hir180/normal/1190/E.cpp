#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
#define double long double

typedef complex<double> pt;
typedef pair<pt,pt> L;
typedef vector<P> poly;
const double EPS = 1e-15;
#define x real()
#define y imag()
bool eq(double a,double b){
  return (-EPS < a-b && a-b < EPS);
}
double dot(pt a,pt b){
	return (conj(a)*b).x;
}
double cross(pt a,pt b){
	return (conj(a)*b).y;
}
int ccw(pt a,pt b,pt c){
	b -= a; c -= a;
	if(cross(b,c) > EPS) return 1; // counter clockwise
	if(cross(b,c) < -EPS) return -1; // clockwise
	if(dot(b,c) < -EPS) return 2; //c-a-b
	if(norm(b) < norm(c)) return -2; //a-b-c
	return 0; //a-c-b
}
bool cmp(const pt& a,const pt& b){
	if(-EPS < a.x-b.x && a.x-b.x < EPS) return a.y < b.y;
	else return a.x < b.x;
}

pair<pt,pt> add(pt c1,double r1,pt c2,double r2){
	//2-circle tangent line
	c2-=c1; // later add c1
	//(0,0) and c2
    //sotogawa
    {
        double c3_x_1 = r1 / norm(c2) * (c2.x * (r1-r2) + c2.y * sqrt(norm(c2)-(r1-r2)*(r1-r2)) );
        double c3_y_1 = r1 / norm(c2) * (c2.y * (r1-r2) - c2.x * sqrt(norm(c2)-(r1-r2)*(r1-r2)) );
        double c3_x_2 = r1 / norm(c2) * (c2.x * (r1-r2) - c2.y * sqrt(norm(c2)-(r1-r2)*(r1-r2)) );
        double c3_y_2 = r1 / norm(c2) * (c2.y * (r1-r2) + c2.x * sqrt(norm(c2)-(r1-r2)*(r1-r2)) );
        pt T2 = pt(c3_x_1,c3_y_1); T2 *= pt(0.0,1.0); pt p1 = pt(c3_x_1,c3_y_1)+c1;
        T2 = pt(c3_x_2,c3_y_2); T2 *= pt(0.0,1.0); pt p2 = pt(c3_x_2,c3_y_2)+c1;
    	return mp(p1,p2);
    }
}
typedef double ld;
int n,m;
pt za[100005];
ld p[2][100005];
int go[400005];
int up[20][400005];
vector<pair<ld,int>>vec;
int nn;
set<P>S;
int main(){
	scanf("%d%d",&nn,&m);
	ld dist = 1e18;
	rep(i,nn){
	    int ax,ay; cin>>ax>>ay;
	    S.insert(P(ax,ay));
	}
	n = S.size(); //cout << n << endl;
	int i = 0;
	for(auto s:S){
	    za[i] = pt((ld)(s.fi),(ld)(s.sc));
	    dist = min(dist,abs(za[i]));
	    i++;
	}
	ld lb = 0.0, ub = dist;
	pt ori = pt(0.0,0.0);
	ld pi = acos((ld)(-1.0));
	while(ub-lb > 1e-7){
		ld mid = (lb+ub)/2;
		vec.clear();
		rep(j,n){
			auto at = add(ori,mid,za[j],0);
			ld ax = atan2(at.fi.y, at.fi.x);
			ld ay = atan2(at.sc.y, at.sc.x);
			if(ax > ay) ay += 2.*pi;
			if(ay-ax >= pi+EPS){
				swap(ax,ay);
				ay += 2.*pi;
			}
			if(ax < 0){
				ax += 2.*pi;
				ay += 2.*pi;
			}
			if(ax >= 2.*pi+EPS){
				ax -= 2.*pi;
				ay -= 2.*pi;
			}
			p[0][j] = ax; p[1][j] = ay;
			while(ax < 4.*pi+EPS){
				vec.pb(mp(ax,j));
				ax += 2.*pi;
				vec.pb(mp(ay,j));
				ay += 2.*pi;
			}
		}
		SORT(vec);
		fill(go,go+400005,INF);
		
		rep(j,n){
			assert(p[0][j] <= p[1][j]);
			while(p[0][j] < 4.*pi+EPS){
				int a = POSL(vec,mp(p[0][j],j)); assert(vec[a].sc == j);
				int b = POSL(vec,mp(p[1][j],j)); assert(vec[b].sc == j);
				assert(a <= b);
				go[a] = min(go[a],b);
				p[0][j] += 2.*pi;
				p[1][j] += 2.*pi;
			}
		}
		
		for(int j=400003;j>=0;j--) go[j] = min(go[j], go[j+1]);
		rep(j,400004) up[0][j] = go[j+1];
		rep(j,19){
			rep(k,400005){
				if(up[j][k] == INF) up[j+1][k] = INF;
				else up[j+1][k] = up[j][up[j][k]];
			}
		}
		int ans = INF;
		rep(i,vec.size()){
			if(vec[i].fi >= 2.*pi+EPS) break;
			
			int use = 0;
			int cur = i;
			for(int k=19;k>=0;k--){
				if(up[k][cur] == INF) continue;
				if(vec[up[k][cur]].fi - vec[i].fi < 2.*pi-EPS){
					use += (1<<k);
					cur = up[k][cur];
				}
			}
			ans = min(ans, use+1);
		}
		
		if(ans <= m) lb = mid;
		else ub = mid;
	}
	printf("%.12Lf\n",lb);
}