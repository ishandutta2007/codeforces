#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long double EPS = 1e-20;
const long double INF = 1e+20;
const long double PI = acos(-1);
int sig(long double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
inline long double ABS(long double a){return max(a,-a);}
struct Pt {
	long double x, y;
	Pt() {}
	Pt(long double x, long double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const long double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const long double &k) const { return Pt(x / k, y / k); }
	long double ABS() const { return sqrt(x * x + y * y); }
	long double abs2() const { return x * x + y * y; }
	long double arg() const { return atan2(y, x); }
	long double dot(const Pt &a) const { return x * a.x + y * a.y; }
	long double det(const Pt &a) const { return x * a.y - y * a.x; }
};
long double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }

int iSP(Pt a, Pt b, Pt c) {
	int s = sig((b - a).det(c - a));
	if (s) return s;
	if (sig((b - a).dot(c - a)) < 0) return -2; // c-a-b
	if (sig((a - b).dot(c - b)) < 0) return +2; // a-b-c
	return 0;
}
int iLL(Pt a, Pt b, Pt c, Pt d) {
	if (sig((b - a).det(d - c))) return 1; // intersect
	if (sig((b - a).det(c - a))) return 0; // parallel
	return -1; // correspond
}
bool iLS(Pt a, Pt b, Pt c, Pt d) {
	return (sig(tri(a, b, c)) * sig(tri(a, b, d)) <= 0);
}
bool iSS(Pt a, Pt b, Pt c, Pt d) {
	return (iSP(a, b, c) * iSP(a, b, d) <= 0 && iSP(c, d, a) * iSP(c, d, b) <= 0);
}
bool iSSstrict(Pt a, Pt b, Pt c, Pt d) {
	return (sig(tri(a, b, c)) * sig(tri(a, b, d)) < 0 && sig(tri(c, d, a)) * sig(tri(c, d, b)) < 0);
}
Pt p[10];
Pt q[1100];
int num[1100][7][7];
pair<long double,int> tmp[1100];
int m;
int solve(set<int>a,int b){
	if(a.size()>__builtin_popcount(b))return 0;
	if(a.size()==0)return 1;
//	for(set<int>::iterator it=a.begin();it!=a.end();it++)printf("%d ",*it);
//	printf(": %d\n",b);
	for(set<int>::iterator it=a.begin();it!=a.end();it++){

		int at=*it;
		for(int i=0;i<m;i++){
			if(b&(1<<i)){
				if(num[at][i][0]==-2)continue;
				int tb=b-(1<<i);
				set<int>to=a;
				to.erase(at);
				for(int j=0;j<m;j++){
					if(num[at][i][j]==-1){
						break;
					}
					to.insert(num[at][i][j]);
				}
				if(solve(to,tb))return 1;
			}
		}
	}
	return 0;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	m=a;
	for(int i=0;i<a;i++){
		int X,Y;scanf("%d%d",&X,&Y);
		p[i]=Pt(X,Y);
	}
	for(int i=0;i<b;i++){
		int X,Y;scanf("%d%d",&X,&Y);
		q[i]=Pt(X,Y);
	}

	for(int i=0;i<b;i++)for(int j=0;j<a;j++)for(int k=0;k<a;k++)num[i][j][k]=-1;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			int sz=0;
			for(int k=0;k<b;k++){
				if(j==k)continue;
				if(iSP(p[i],q[k],q[j])==2){
		//			printf("%d %d %d\n",i,j,k);
				//	if(num[j][i][0]==-1||iSP(q[j],q[k],q[num[j][i][0]])==2){
//
//						num[j][i][0]=k;
//					}
					tmp[sz++]=make_pair((q[j]-q[k]).abs2(),k);
				}
			}
			if(sz>=a){
				num[j][i][0]=-2;
			}else{
				for(int k=0;k<sz;k++){
					num[j][i][k]=tmp[k].second;
				}
			}
	//		printf("%d %d: %d\n",j,i,num[j][i][0]);
		}
	}
	int ret=0;
	for(int i=0;i<b;i++){
		set<int>st;
		st.insert(i);
		if(solve(st,(1<<a)-1))ret++;
	//	printf("\n");
	}
	printf("%d\n",ret);
}