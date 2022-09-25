// copied from my son:wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rnd(time(0));
 
const int N=50005;
const double eps=1e-9;
const double PI=acos(-1.0);
const double ANG=0.1145141919810;
const double CANG=cos(ANG);
const double SANG=sin(ANG);
 
inline bool same(double x,double y){return fabs(x-y)<eps;}
inline double sqr(double x){return x*x;}
 
struct Point{
	double x,y;
	Point(double _x=0,double _y=0):x(_x),y(_y){}
	double len2(){return sqr(x)+sqr(y);}
	double len(){return sqrt(len2());}
	void rot(){
		double _x=x,_y=y;
		x=_x*CANG+_y*SANG;
		y=-_x*SANG+_y*CANG;
	}
	friend bool operator < (const Point &a,const Point &b){
		return a.x<b.x;
	}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend double operator % (const Point &a,const Point &b){
		return a.x*b.y-a.y*b.x;
	}
	friend double operator * (const Point &a,const Point &b){
		return a.x*b.x+a.y*b.y;
	}
	friend Point operator * (const Point &a,const double &t){
		return Point(a.x*t,a.y*t);
	}
	friend Point operator / (const Point &a,const double &t){
		return Point(a.x/t,a.y/t);
	}
};
inline double Fix(double x){
	while(x>PI)x-=2*PI;
	while(x<=-PI)x+=2*PI;
	return x;
}
double ans;
int n,l,k;
inline void calc(vector<Point> a){
	static vector<Point> b;
	for(auto &it:a)it.rot();
	sort(a.begin(),a.end());
	b=a,shuffle(b.begin(),b.end(),rnd);
	for(int i=0;i<(int)b.size();++i){ //  i 
		double l=0,r=ans;
		bool fir=0;
		while((r-l)/max(1.0,l)>eps){
			double mid=(l+r)/2;
			if(l<1&&r>1)mid=1;
			else if(l<1)mid=(l+r)/2;
			else mid=sqrt(l*r);
			
			if(!fir)mid=r,fir=1;
			int pos1=lower_bound(a.begin(),a.end(),Point(b[i].x-2*mid-eps,0))-a.begin();
			int pos2=upper_bound(a.begin(),a.end(),Point(b[i].x+2*mid+eps,0))-a.begin();
			if(pos2-pos1<k){l=mid;continue;}
			vector<pair<double,int> > range;
			int c=0;
			for(int j=pos1;j<pos2;++j){
				Point p=a[j]-b[i];
				if(p.len()>2*mid)continue;
				if(p.len()<eps){c++;continue;}
				double d=p.len();
				double ang1=atan2(p.y,p.x),ang2=acos(d/2/mid);
				double L=Fix(ang1-ang2),R=Fix(ang1+ang2);
				if(L>R)c++;
				range.emplace_back(L,1);
				range.emplace_back(R,-1);
			}
			bool ok=c>=k;
			sort(range.begin(),range.end());
			for(auto it:range){
				c+=it.second;
				if(ok|=c>=k)break;
			}
			if(ok)r=ans=mid;
			else l=mid;
		}
	}
}
 
void Solve(){
	cin>>n>>l>>k;
	ans=1e9;
	static pair<int,int> a[N];
	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;
	}
	set<pair<int,int> > S;
	for(int i=1;i<=n;++i){
		S.insert(a[i]);
		if(i>l){
			S.erase(a[i-l]);
		}
		auto it=S.lower_bound(make_pair(int(a[i].first-2*ans-1),0));
		vector<Point> ask;
		while(it!=S.end()){
			pair<int,int> t=*it;
			if(t.first-a[i].first>2*ans)break;
			if(1.0*(t.first-a[i].first)*(t.first-a[i].first)+1.0*(t.second-a[i].second)*(t.second-a[i].second)<4*ans*ans+eps){
				ask.push_back(Point(t.first,t.second));
			}
			it++;
		}
		calc(ask);
	}
	cout<<ans<<'\n';
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}