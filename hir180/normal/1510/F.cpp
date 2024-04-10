#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
#define a first
#define b second

template<class t,class u>bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u>bool chmin(t&a,u b){if(a>b){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>&p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t>
ostream&operator<<(ostream&os,const vector<t>&v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template<class t>
using vc=vector<t>;

using vi=vc<int>;

using pi=pair<int,int>;

using ld=long double;
using cm=complex<ld>;
#define x real()
#define y imag()
ld eps=1e-12;
const ld PI=acos(ld(-1));
int sgn(ld a){return a<-eps?-1:(a>eps?1:0);}
int sgn(ld a,ld b){return sgn(a-b);}
ld dot(cm a,cm b){return a.x*b.x+a.y*b.y;}
ld crs(cm a,cm b){return a.x*b.y-a.y*b.x;}
ld crs(cm a,cm b,cm c){return crs(b-a,c-a);}
int ccw(cm a,cm b){return sgn(crs(a,b));}
int ccw(cm a,cm b,cm c){return sgn(crs(b-a,c-a));}
int qeq(ld a,ld b,ld c,ld&d,ld&e){
	dmp(a);
	dmp(b);
	dmp(c);
	if(sgn(a)==0){
		if(sgn(b)==0)return 0;
		d=-c/b;
		return 1;
	}
	ld f=b*b-4*a*c;
	dmp(f);
	if(sgn(f)<0)return 0;
	ld g=sqrt(max(f,ld(0)));
	d=(-b-g)/(2*a);
	e=(-b+g)/(2*a);
	return sgn(f)+1;
}
using ln=pair<cm,cm>;
cm dir(ln a){return a.b-a.a;}
cm eval(ln a,ld b){return a.a+dir(a)*b;}
using cr=pair<cm,ld>;
int ccl(cr a,ln b,ld&c,ld&d){
	dmp(a);
	dmp(b);
	cm e=dir(b);
	cm f=b.a-a.a;
	return qeq(norm(e),2*dot(e,f),norm(f)-a.b*a.b,c,d);
}

tuple<ld,cm,int> sub(ld a,cm p,cm lto,cm rto){
	if(sgn(p.y)<=0)exit(0);
	//assert(sgn(p.y)>0);
	ld c2=abs(p-cm(-a,0))+abs(p-cm(a,0));
	//ld c=max(c2/2,a);
	ld c=c2/2;
	ld b=sqrt(c*c-a*a);
	
	a/=c;
	p=cm(p.x/c,p.y/b);
	lto=cm(lto.x/c,lto.y/b);
	rto=cm(rto.x/c,rto.y/b);
	
	dmp(a);
	//assert(sgn(abs(a),1)<=0);
	
	auto getarg=[&](ln tar){
		dmp(tar);
		ld t0,t1;
		int cnt=ccl(cr(cm(0,0),1),tar,t0,t1);
		dmp(cnt);
		if(cnt!=2)exit(0);
		assert(cnt==2);
		/*cm res=eval(tar,t0);
		if(res.y>0)return res;
		res=eval(tar,t1);
		if(res.y>0)return res;
		assert(false);*/
		ld t=max(t0,t1);
		cm res=eval(tar,t);
		if(sgn(res.y)<=0)return PI;
		else return arg(res);
	};
	ld la=getarg(ln(lto,cm(-a,0)));
	ld ra=getarg(ln(cm(a,0),rto));
	
	ld from=arg(p);
	ld to=min(la,ra);
	
	assert(sgn(to,PI)<0);
	
	ld area=(to-from);
	area-=a*sin(from);
	area+=a*sin(to);
	area/=2;
	
	return make_tuple(area*b*c,cm(cos(to)*c,sin(to)*b),la<ra?0:1);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	ld tot;cin>>tot;
	vc<cm> ps(n);
	rep(i,n){
		int a,b;cin>>a>>b;
		ps[i]=cm(a,b);
	}
	
	int lf=-1,rt=-1;
	cm cur;
	{
		cm d=ps[0]-ps[1];
		d/=abs(d);
		ld use=0;
		bool found=false;
		rng(i,1,n){
			use+=abs(ps[i]-ps[i-1]);
			ld rem=tot-use;
			assert(sgn(rem)>=0);
			if(i>=2){
				cm z=ps[i]-ps[0];
				ld t=(rem*rem-norm(z))/(2*(rem-dot(d,z)));
				cm p=ps[0]+t*d;
				if(sgn(t)>=0&&ccw(ps[i],p,ps[(i+1)%n])>=0){
					lf=1;
					rt=i;
					cur=p;
					found=true;
					break;
				}
			}
		}
		assert(found);
	}
	
	dmp(lf);
	dmp(rt);
	dmp(cur);
	
	ld ans=0;
	rep(i,n)ans+=crs(ps[i],ps[(i+1)%n]);
	ans/=2;
	while(1){
		cm cent=(ps[lf]+ps[rt])*ld(0.5);
		cm rot=ps[rt]-ps[lf];
		rot=conj(rot);
		rot/=abs(rot);
		auto conv=[&](cm src){
			return (src-cent)*rot;
		};
		auto [area,nx,tp]=sub(abs(ps[rt]-ps[lf])/2,conv(cur),conv(ps[(lf+1)%n]),conv(ps[(rt+1)%n]));
		ans+=area;
		cur=nx*conj(rot)+cent;
		if(tp==0){
			if(lf==0)break;
			lf=(lf+1)%n;
		}else{
			rt=(rt+1)%n;
		}
	}
	cout<<ans<<endl;
}