#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<complex>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 1
#define CI complex<int>

vector<CI> p1,p2;

inline double mini(CI x, CI y){
	double d1 = x.real()*x.real()+x.imag()*x.imag();
	double d2 = y.real()*y.real()+y.imag()*y.imag();
	CI z= y-x;
	double d3 = z.real()*z.real()+z.imag()*z.imag();
	if(y==CI(0,0)) return 0;

	double u = (conj(z)*x+conj(x)*z).real();
	double arg = -u/(2.*d3);
	double xx;
	if(arg>=0.-1e-9 && arg<= 1.+1e-9){
		xx = d1+u*arg+d3*arg*arg;
	}
	else xx = d1;

	return min(min(d1,d2),xx);
}

inline bool czyzero(int u,int v){
		vector<CI> g;
		FOR(i,0,2) FOR(j,0,2) g.pb(p1[i+u]-p2[j+v]);
		FOR(i,0,4) if(g[i]==CI(0,0)) return true;
		
		double sum = 0.;
		sum = abs(arg(g[0]/g[1]))+abs(arg(g[0]/g[2]))+abs(arg(g[2]/g[1]));
		if( abs(sum-2*M_PI) < 1e-7) return true;
		sum = abs(arg(g[0]/g[1]))+abs(arg(g[0]/g[3]))+abs(arg(g[3]/g[1]));
		if( abs(sum-2*M_PI) < 1e-7) return true;
		sum = abs(arg(g[0]/g[2]))+abs(arg(g[0]/g[3]))+abs(arg(g[2]/g[3]));
		if( abs(sum-2*M_PI) < 1e-7) return true;
		sum = abs(arg(g[3]/g[1]))+abs(arg(g[3]/g[2]))+abs(arg(g[2]/g[1]));
		if( abs(sum-2*M_PI) < 1e-7) return true;
		return false;
}

int main(){
	make2(a,b); CI P(a,b);
	make(n); 
	FOR(i,0,n){
		make2(a,b); p1.pb(CI(a,b)-P);
	}
	make2(c,d) CI Q(c,d);
	make(m);
	FOR(i,0,m){
		make2(a,b); p2.pb(CI(a,b)-Q);
	}
	p1.pb(p1[0]);
	p2.pb(p2[0]);


	Q = Q-P;
	
	int l = Q.real()*Q.real()+Q.imag()*Q.imag();
	//debug(l);
	//debug2(Q.real(),Q.imag());
	FOR(i,0,n) FOR(j,0,m){
		VI x; 
		FOR(u,0,2) FOR(v,0,2){
			CI haha = p1[i+u]-p2[j+v]; 
			x.pb(haha.real()*haha.real() + haha.imag()*haha.imag());
	//		debug2(haha.real(),haha.imag());
		}
		double mins = 1e9;
		mins = min(mins, mini(p1[i]-p2[j],p1[i]-p2[j+1]));
		mins = min(mins, mini(p1[i]-p2[j],p1[i+1]-p2[j]));
		mins = min(mins, mini(p1[i]-p2[j+1],p1[i+1]-p2[j+1]));
		mins = min(mins, mini(p1[i+1]-p2[j],p1[i+1]-p2[j+1]));
	
		if(czyzero(i,j)) x.pb(0);
		sort(x.begin(),x.end());
		if(l>=x[0] && l<=x[x.size()-1]){
			printf("YES\n");
			return 0;
		}
		if(l >= mins-1e-9 && l<=x[x.size()-1]){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");

	return 0;
}