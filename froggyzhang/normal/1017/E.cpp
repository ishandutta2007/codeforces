#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const double eps=1e-8;
const double PI=acos(-1.0);
int n,m;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){x=_x,y=_y;}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
	friend bool operator < (const Point &a,const Point &b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
	inline ll len(){
		return 1LL*x*x+1LL*y*y;
	}
}LTL;
typedef vector<Point> poly;
poly A,B;
int an,bn;
pair<double,ll> a[N],b[N];
double Get(Point a,Point b){
	double tmp=atan2(b.y,b.x)-atan2(a.y,a.x);
	while(tmp<0)tmp+=2*PI;
	return tmp;	
}
inline bool Para(Point a,Point b){
	return a%b==0;
}
inline bool Left(Point a,Point b){
	return b%a>0;
} 
//
inline bool cmp(Point a,Point b){
	a=a-LTL,b=b-LTL;
	return Para(a,b)?a.len()<b.len():Left(b,a);
} 
poly Convex(poly a){
	static poly st;
	st.clear();
	LTL=(*min_element(a.begin(),a.end()));
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();++i){
		while(st.size()>1&&!Left(a[i]-st[st.size()-2],st.back()-st[st.size()-2]))st.pop_back();
		st.push_back(a[i]);
	}
	return st;
}
void Min_rep(pair<double,ll> *a,int n){
	static pair<double,ll> c[N<<1];
	for(int i=1;i<=n;++i){
		c[i]=c[i+n]=a[i];
	}
	int pos=1;
	for(int i=1;i<=n;){
		int j=i,k=i+1;
		while(k<=2*n&&c[j]<=c[k]){
			if(c[j]<c[k])j=i;
			else ++j;
			++k;
		}
		while(i<=j){
			i+=k-j;	
			if(i<=n)pos=i;
		}
	}
	rotate(a+1,a+pos,a+n+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	A.resize(n),B.resize(m);
	for(int i=0;i<n;++i){
		cin>>A[i].x>>A[i].y;
	}
	for(int i=0;i<m;++i){
		cin>>B[i].x>>B[i].y;
	}
	A=Convex(A),B=Convex(B);
	n=A.size(),m=B.size();
	if(n==2&&m==2){
		cout<<(((A[1]-A[0]).len()==(B[1]-B[0]).len())?"YES\n":"NO\n");
		return 0;	
	}
	for(int i=0;i<n;++i){
		a[++an]=make_pair(Get(A[i]-A[(i+1)%n],A[(i+2)%n]-A[(i+1)%n]),(A[i]-A[(i+1)%n]).len());
	}
	for(int i=0;i<m;++i){
		b[++bn]=make_pair(Get(B[i]-B[(i+1)%m],B[(i+2)%m]-B[(i+1)%m]),(B[i]-B[(i+1)%m]).len());
	}
	if(an^bn){
		cout<<"NO\n";return 0;	
	}
	Min_rep(a,an),Min_rep(b,bn);
	for(int i=1;i<=an;++i){
		if(fabs(a[i].first-b[i].first)>eps||a[i].second^b[i].second){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}