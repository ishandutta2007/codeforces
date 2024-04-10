#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3fll;
int n,LN,RN,UN,DN;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0):x(_x),y(_y){}
}p[N];
struct Rec{
	int x1,y1,x2,y2;
	Rec(){x1=y1=inf,x2=y2=-inf;}
	Rec(Point a){x1=x2=a.x,y1=y2=a.y;}
	friend Rec operator | (const Rec &a,const Point &p){
		Rec b;
		b.x1=min(a.x1,p.x),b.x2=max(a.x2,p.x);
		b.y1=min(a.y1,p.y),b.y2=max(a.y2,p.y);
		return b;
	}
	ll val(){
		return 1LL*(x2-x1)*(y2-y1);
	}
};
namespace Type_1{
	ll Solve(){
		static Rec pre[N],suf[N];
		sort(p+1,p+n+1,[&](Point a,Point b){return a.x<b.x;});
		ll ans=infll;
		pre[1]=Rec(p[1]),suf[n]=Rec(p[n]);
		for(int i=2;i<=n;++i)pre[i]=pre[i-1]|p[i];
		for(int i=n-1;i>=1;--i)suf[i]=suf[i+1]|p[i];
		for(int i=1;i<n;++i)ans=min(ans,pre[i].val()+suf[i+1].val());
		sort(p+1,p+n+1,[&](Point a,Point b){return a.y<b.y;});
		pre[1]=Rec(p[1]),suf[n]=Rec(p[n]);
		for(int i=2;i<=n;++i)pre[i]=pre[i-1]|p[i];
		for(int i=n-1;i>=1;--i)suf[i]=suf[i+1]|p[i];
		for(int i=1;i<n;++i)ans=min(ans,pre[i].val()+suf[i+1].val());
		return ans;
	}
}
namespace Type_2{
	class Segment_Tree{
		int Len;
		struct node{
			ll mn;
		}t[N<<2];
		#define ls u<<1
		#define rs u<<1|1
		inline void update(int u){
			t[u].mn=min(t[ls].mn,t[rs].mn);
		}
		void build(int u,int L,int R,ll *a){
			if(L==R){
				t[u].mn=a[L];
				return;
			}
			int mid=(L+R)>>1;
			build(ls,L,mid,a);
			build(rs,mid+1,R,a);
			update(u);
		}
		ll _query(ll u,int L,int R,int l,int r){
			if(L>=l&&R<=r){
				return t[u].mn;
			}
			ll mn=infll;
			int mid=(L+R)>>1;
			if(l<=mid)mn=min(mn,_query(ls,L,mid,l,r));
			if(r>mid)mn=min(mn,_query(rs,mid+1,R,l,r));
			return mn;
		}
	public:
		void init(int _n,ll *a){
			Len=_n;
			build(1,1,Len,a);
		}
		ll Query(int l,int r){
			if(l>r)return infll;
			return _query(1,1,Len,l,r);
		}
	}T[4];
	ll Solve(){
		static ll a1[N],a2[N],a3[N],a4[N];
		static int sufU[N],sufD[N];
		sort(p+1,p+n+1,[&](Point a,Point b){return a.x<b.x;});
		sufU[n]=-inf,sufD[n]=inf;
		Rec zz;
		a1[n]=a2[n]=a3[n]=a4[n]=1LL*p[n].x*(UN-DN);
		zz=zz|p[n];
		for(int i=n-1;i>=1;--i){
			a1[i]=1LL*(RN-LN)*(zz.y2-zz.y1)+1LL*p[i].x*(UN-DN);
			a2[i]=1LL*(RN-LN)*(zz.y2)+1LL*p[i].x*(UN-DN);
			a3[i]=1LL*(RN-LN)*(-zz.y1)+1LL*p[i].x*(UN-DN);
			a4[i]=1LL*p[i].x*(UN-DN);
			zz=zz|p[i];
			sufU[i]=max(sufU[i+1],p[i+1].y);
			sufD[i]=min(sufD[i+1],p[i+1].y);
		}
		T[0].init(n,a1);
		T[1].init(n,a2);
		T[2].init(n,a3);
		T[3].init(n,a4);
		ll ans=infll;
		for(int i=1,j=n,k=n,nowD=inf,nowU=-inf;i<=n;++i){
			while(j>=1&&sufD[j]>=nowD)--j;
			while(k>=1&&sufU[k]<=nowU)--k;
			ans=min(ans,T[0].Query(i,min(j,k))-1LL*p[i].x*(UN-DN));
			ans=min(ans,T[1].Query(max(i,j+1),k)-1LL*p[i].x*(UN-DN)-1LL*nowD*(RN-LN));
			ans=min(ans,T[2].Query(max(i,k+1),j)-1LL*p[i].x*(UN-DN)+1LL*nowU*(RN-LN));
			ans=min(ans,T[3].Query(max(i,max(j+1,k+1)),n)-1LL*p[i].x*(UN-DN)+max(0LL,1LL*(nowU-nowD)*(RN-LN)));
			nowD=min(nowD,p[i].y);
			nowU=max(nowU,p[i].y);
		}
		return ans;
	}
}
namespace Type_3{
	inline Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	inline Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	inline ll operator % (const Point &a,const Point &b){
		return 1LL*a.x*b.y-1LL*a.y*b.x;
	}
	inline bool Left(const Point &a,const Point &b){
		return b%a>0;
	}
	struct Tu{
		vector<Point> p;
		void Insert(const Point &a){
			while(p.size()>1&&!Left(a-p[p.size()-2],p.back()-p[p.size()-2]))p.pop_back();
			p.push_back(a);
		}
		friend Tu operator | (const Tu &a,const Tu &b){
			Tu c;
			int i=0,j=0;
			while(i<a.p.size()||j<b.p.size()){
				if(i<a.p.size()&&(j==b.p.size()||(a.p[i].x<b.p[j].x||(a.p[i].x==b.p[j].x&&a.p[i].y<b.p[j].y))))c.Insert(a.p[i++]);
				else c.Insert(b.p[j++]);
			}
			return c;
		}
		ll Query(Point a){
			auto calc=[&](Point a,Point b)->ll{
				return 1LL*a.x*b.y+1LL*a.y*b.x;
			};
			int l=0,r=(int)p.size()-1,ans=(int)p.size()-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(calc(a,p[mid])<=calc(a,p[mid+1]))r=ans=mid;
				else l=mid+1;
			}
			return calc(a,p[ans]);
		}
	};
	class Segment_Tree{
		int Len;
		struct node{
			Tu p;
		}t[N<<3];
		#define ls u<<1
		#define rs u<<1|1
		inline void update(int u){
			t[u].p=t[ls].p|t[rs].p;
		}
		void build(int u,int L,int R,Point *a){
			if(L==R){
				t[u].p.p.clear();
				t[u].p.Insert(a[L]);
				return;
			}
			int mid=(L+R)>>1;
			build(ls,L,mid,a);
			build(rs,mid+1,R,a);
			update(u);
		}
		ll _query(ll u,int L,int R,int l,int r,Point a){
			if(L>=l&&R<=r){
				return t[u].p.Query(a);
			}
			ll mn=infll;
			int mid=(L+R)>>1;
			if(l<=mid)mn=min(mn,_query(ls,L,mid,l,r,a));
			if(r>mid)mn=min(mn,_query(rs,mid+1,R,l,r,a));
			return mn;
		}
	public:
		void init(int _n,Point *a){
			Len=_n;
			build(1,1,Len,a);
		}
		ll Query(int l,int r,Point a){
			if(l>r)return infll;
			return _query(1,1,Len,l,r,a);
		}
	}T;
	ll mian(){
		sort(p+1,p+n+1,[&](Point a,Point b){return a.x==b.x?a.y<b.y:a.x<b.x;});
		int tot=0;
		static Point a[N<<1],c[N<<1];
		auto Add=[&](int x,int y)->void{
			++tot;
			a[tot]=Point(RN-x,y-DN);
			c[tot]=Point(x,y);
		};
		for(int i=1,las=-inf;i<=n;++i){
			if(p[i].y>=las){
				if(las>-inf)Add(p[i].x,las);
				Add(p[i].x,p[i].y);
				las=p[i].y;
			}
		}
		T.init(tot,a);
		sort(p+1,p+n+1,[&](Point a,Point b){return a.y==b.y?a.x<b.x:a.y<b.y;});
		int l=1,r=0;
		ll ans=infll;
		auto Ask=[&](int x,int y)->ll{
			while(l<=tot&&c[l].y<y)++l;
			while(r<tot&&c[r+1].x<=x)++r;
			return T.Query(l,r,Point(x-LN,UN-y));
		};
		for(int i=1,las=-inf;i<=n;++i){
			if(p[i].x>=las){
				if(las>-inf)ans=min(ans,Ask(las,p[i].y));
				ans=min(ans,Ask(p[i].x,p[i].y));
				las=p[i].x;
			}
		}
		return ans;
	}
	ll Solve(){
		ll tmp=mian();
		for(int i=1;i<=n;++i){
			p[i].x=RN-p[i].x+LN;
		}
		tmp=min(tmp,mian());
		for(int i=1;i<=n;++i){
			p[i].x=RN-p[i].x+LN;
		}
		return tmp;
	}
}
void Solve(){
	LN=inf,RN=-inf,DN=inf,UN=-inf;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
		LN=min(LN,p[i].x);
		RN=max(RN,p[i].x);
		DN=min(DN,p[i].y);
		UN=max(UN,p[i].y);
	}
	if(n<=2){
		cout<<0<<'\n';return;
	}
	cout<<min(min(Type_1::Solve(),Type_2::Solve()),Type_3::Solve())<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}