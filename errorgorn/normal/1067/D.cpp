#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct line{
	double m,c;
	
	double eval(double x){
		return m*x+c;
	}
};

struct HULL{ //max hull
	deque<line> v;
	
	double POI(line a,line b){
		return (a.c-b.c)/(b.m-a.m);
	}
	
	void ins(line a){ //insert by increasing gradient
		if (!v.empty() && v.back().m==a.m){
			if (v.back().c>a.c) return;
			v.pob();
		}
		
		while (sz(v)>=2 && POI(v[sz(v)-2],v[sz(v)-1])>=POI(v[sz(v)-1],a)) v.pob();
		v.pub(a);
	}
	
	double get(double x){
		while (sz(v)>=2 && POI(v[0],v[1])<=x) v.pof();
		return v[0].eval(x);
	}
} hull;

struct mat{
	double arr[3][3]={};
};

struct vec{
	double arr[3]={};
};

mat mul(mat a,mat b){
	mat res;
	rep(x,0,3) rep(y,0,3) rep(z,0,3){
		res.arr[x][z]=(res.arr[x][z]+a.arr[x][y]*b.arr[y][z]);
	}
	return res;
}

vec mul(mat a,vec b){
	vec res;
	rep(x,0,3) rep(y,0,3){
		res.arr[x]=(res.arr[x]+a.arr[x][y]*b.arr[y]);
	}
	return res;
}

mat pp[40];

int n,T;
int arr[100005];
int brr[100005];
double p[100005];

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n>>T;
	rep(x,1,n+1) cin>>arr[x]>>brr[x]>>p[x];
	
	vector<int> idx;
	rep(x,1,n+1) idx.pub(x);
	sort(all(idx),[](int i,int j){
		return p[i]<p[j];
	});
	
	for (auto it:idx) hull.ins({p[it],arr[it]*p[it]});
	
	double mx=0;
	rep(x,1,n+1) mx=max(mx,brr[x]*p[x]);
	
	double ans=0;
	int t=0;
	while (t<T){
		hull.get(t*mx-ans);
		double p=hull.v[0].m,pa=hull.v[0].c;
		pp[0].arr[0][0]=1-p,pp[0].arr[0][1]=p,pp[0].arr[0][2]=pa;
		pp[0].arr[1][1]=1,pp[0].arr[1][2]=mx;
		pp[0].arr[2][2]=1;
		
		rep(x,1,40) pp[x]=mul(pp[x-1],pp[x-1]);
		
		vec v={ {ans,t*mx,1} };
		
		double thres=1e100;
		if (sz(hull.v)>=2) thres=hull.POI(hull.v[0],hull.v[1]);
		
		rep(x,40,0){
			int nt=t+(1LL<<x);
			vec v2=mul(pp[x],v);
			if (nt<T && nt*mx-v2.arr[0]<thres){
				t=nt;
				v=v2;
			}
		}
		
		t++;
		ans=mul(pp[0],v).arr[0];
		
		//cout<<t<<" "<<ans<<endl;
	}
	
	cout<<fixed<<setprecision(12)<<ans<<endl;
}