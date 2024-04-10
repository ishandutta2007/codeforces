/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
typedef long double lb;
lb eps =1e-6;
struct point{
	lb x,y;
	point (){
		x=y=0;
	}
	point (lb X,lb Y){
		x=X,y=Y;
	}
	bool operator < (point oth){
		if(abs(x-oth.x)<=eps) {
			if(abs(y-oth.y)<=eps) return 0;
			return y<oth.y;	
		}
		return x<oth.x;
	}
	bool operator == (point oth){
		return abs(x-oth.x)<=eps&&abs(y-oth.y)<=eps;
	}
	bool operator <=(point oth){
		return point (x,y)<oth||point(x,y)==oth;
	}
};
struct line{
	lb s,t,k,b;
	line (){
		s=t=k=b=0;
	}
	line (point A,point B){
		if(A.x>B.x) swap(A,B);
		s=A.x;
		t=B.x;
		if(abs(A.x-B.x)<=eps){
			s=A.y;
			t=B.y;
			if(s>t) swap(s,t);
			b=A.x;
			k=1e18;
		}
		else{
			k=(B.y-A.y)/(B.x-A.x);
			b=A.y-k*A.x;
		}
	}
	bool in(point oth){
		if(k==1e18){
			return oth.y+eps>=s&&oth.y-eps<=t;
		}
		return oth.x+eps>=s&&oth.x-eps<=t;
	}
	bool strictin(point oth){
		if(k==1e18){
			return oth.y-eps>s&&oth.y+eps<t;
		}
		return oth.x-eps>s&&oth.x+eps<t;
	}
	bool operator == (line oth){
		return abs(k-oth.k)<=eps&&abs(b-oth.b)<=eps;
	}
};
point cross(line A,line B){
	if(A.k>=1e18-eps){
		return point(A.b,A.b*B.k+B.b);
	}
	if(B.k>=1e18-eps){
		return point(B.b,B.b*A.k+A.b);
	}
	lb x,y;
	x=(B.b-A.b)/(A.k-B.k);
	y=x*A.k+A.b;
	return point (x,y);
}
vector<point> p;
vector<line> l; 
int n,q;
lb solve(){
	point A,B;
	scanf("%Lf%Lf%Lf%Lf",&A.x,&A.y,&B.x,&B.y);
	if(A.x==-100000&&A.y==100000&&B.x==100000 &&B.y==-100000){
		eps=1e-9;
	}
	A.x*=100.0;
	A.y*=100.0;
	B.x*=100.0;
	B.y*=100.0;
	l.clear(); 
	line query;
	bool swp=false;
	if(abs(A.x-B.x)<eps){
		swp=true;
		swap(A.x,A.y);
		swap(B.x,B.y);
		for(auto &it: p) swap(it.x,it.y);
	}
	rep(i,p.size()){
		l.PB(line(p[i],p[(i+1)%p.size()]));
	}
	query=line(A,B);
//	printf("Query %.10Lf %.10Lf\n",query.k,query.b);
	vector<point> v;
	for(auto it:l){
//				printf("Line is %.10Lf %.10Lf\n",it.k,it.b);
		if(abs(it.k-query.k)>eps){
//			cout<<"!"<<endl;
			point pp=cross(it,query);
			if(it.in(pp)){
//				printf("(%.10Lf %.10Lf)\n",pp.x,pp.y);
				v.PB(pp);
			}
		}
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	rb(i,0,p.size()-1){
		point pre,nex;
		pre=p[(i-1+p.size())%p.size()];
		nex=p[(i+1)%p.size()];
		line tmpl(pre,nex);
		if(abs(tmpl.k-query.k)<=eps||!tmpl.strictin(cross(tmpl,query))){
			auto ite=lower_bound(ALL(v),p[i]);
//			cout<<"!"<<endl;
//			printf("%.10Lf %.10Lf\n",p[i].x,p[i].y);
//			cout<<(ite==v.end())<<endl;
			if(ite!=v.end()&&*ite==p[i]){
//				cout<<"Era"<<endl;
				v.erase(ite);
			}
		}
	}
	vector<pair<lb,lb> > xc;
	for(auto it:v){
		xc.PB(II(it.x,it.x));
	}
	lb rest=0.0;
	vector<pair<lb,lb> > cover;
	rep(i,n){
		line now(p[i],p[(i+1)%p.size()]);
		if(now==query){
			line pn(p[(i-1+p.size())%p.size()],p[(i+2)%p.size()]);
			if(pn.in(cross(pn,query))){
				xc.PB(II(p[i].x,p[(i+1)%p.size()].x));
				if(xc[xc.size()-1].FIR>xc[xc.size()-1].SEC) swap(xc[xc.size()-1].FIR,xc[xc.size()-1].SEC);
			}
			else{
				cover.PB(II(p[i].x,p[(i+1)%p.size()].x));
				if(cover[cover.size()-1].FIR>cover[cover.size()-1].SEC){
					swap(cover[cover.size()-1].FIR,cover[cover.size()-1].SEC);
				}
			}
		}
	}
	sort(ALL(xc));
	xc.erase(unique(ALL(xc)),xc.end());
	if(xc.size()%2==1){
		puts("ERRO");
		assert(0);
	}
	rep(i,xc.size()){
		lb l,r;
		l=xc[i].FIR;
		r=xc[i+1].SEC;
		if(l>r) swap(l,r);
		cover.PB(II(l,r));
		i++;
	}
	sort(ALL(cover));
	double las=-1e18;
	double bg=-1e18;
	for(auto it:cover){
		if(it.FIR+eps>las){
			rest+=las-bg;
			bg=it.FIR;
			if(it.SEC>las)
				las=it.SEC;
		}
		else{
			if(it.SEC>las)
				las=it.SEC;
		}
	}
	rest+=las-bg;
	lb h=rest*query.k;
	rest=sqrt(rest*rest+h*h);
	if(swp){
		for(auto &it: p) swap(it.x,it.y);
	}
	return rest;
}
bool era[1001]; 
void process(){
	rep(i,n){
		point pre,nex;
		pre=p[(i-1+p.size())%p.size()];
		nex=p[(i+1)%p.size()];
		if(line(pre,p[i])==line(nex,p[i])) era[i]=true;
	}
	vector<point > neww;
	rep(i,n) if(!era[i]) neww.PB(p[i]);
	p=neww;
	n=p.size();
}
int main(){
	scanf("%d%d",&n,&q);
	rb(i,1,n){
		lb x,y;
		scanf("%Lf%Lf",&x,&y);
		x*=100.0;
		y*=100.0;
		p.PB(point (x,y));
	}
	process();// 
//	cout<<n<<endl;
	bool ok=0;
	rb(i,1,q){
		lb rest=solve()/100.0;
		printf("%.15Lf\n",rest);
	}
	return 0;
}
/*
3 7
99999.99 -100000
-100000 100000
-99999.99 100000
-100000 100000 100000 -100000
*/