#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include <functional>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 5e5+10;
const int INF = -0xc0c0c0c0;

struct vec
{
	public:
		int x,y;
		vec(int _x=0, int _y=0): x(_x), y(_y) {}

		vec& operator -= (const vec& o) {x-=o.x, y-=o.y; return *this;}
		vec& operator += (const vec& o) {x+=o.x, y+=o.y; return *this;}

		friend vec operator + (vec a, const vec& b) {return a+=b;}
		friend vec operator - (vec a, const vec& b) {return a-=b;}

		ll operator / (const vec& o) const {return (ll)x*o.y-(ll)y*o.x;}
		bool operator < (const vec& o) const {return *this/o<0;}
		bool operator > (const vec& o) const {return *this/o>0;}
};

struct Qry
{
	public:
		int t, a, b;
		void in()
		{
			scanf("%d%d", &t, &a);
			if(t==1||t==3) scanf("%d", &b);
		}
} q[MN];

using PID = std::pair<vec, int>;

struct ST // point update max query
{
	public:
		int v[MN*4];
		ST() {memset(v, 0xc0, sizeof v);}
		void upd(int n, int l, int r, int q, int nv)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				if(q<m) upd(n<<1, l, m, q, nv);
				else upd(n<<1|1, m, r, q, nv);
				v[n]=std::max(v[n<<1], v[n<<1|1]);
			}
			else
				v[n]=nv;
		}
		int qry(int n, int l, int r, int ql, int qr)
		{
			if(ql<=l&&r<=qr)
				return v[n];
			else
			{
				int m=l+(r-l)/2, f=-INF;
				if(ql<m) ckmax(f, qry(n<<1, l, m, ql, qr));
				if(m<qr) ckmax(f, qry(n<<1|1, m, r, ql, qr));
				return f;
			}
		}
};
ST st;

int R, N, M, a[MN], b[MN], am[MN], bm[MN];
std::vector<PID> lb, rb;

bool bad(int a, int b)
{
	vec l = std::max(lb[a-1].first, lb[b-1].first);
	vec r = std::min(rb[a-1].first, rb[b-1].first);
	return vec{l.y, -l.x}<r;
}

int main()
{
	scanf("%d%d", &R, &N);
	for(int i=0;i<N;++i)
	{
		q[i].in();
		if(q[i].t==1)
		{
			lb.push_back({{q[i].a+R, q[i].b}, M});
			rb.push_back({{q[i].a-R, q[i].b}, M});
			++M;
		}
	}

	std::sort(lb.begin(), lb.end(), std::greater<PID>());
	std::sort(rb.begin(), rb.end());
	for(int i=0, j;i<lb.size();++i)
	{
		if(!i || lb[i-1].first > lb[i].first)
			j=i;
		a[lb[i].second]=i;
		am[lb[i].second]=j;
	}
	for(int i=0, j;i<rb.size();++i)
	{ 
		if(!i || rb[i-1].first < rb[i].first)
			j=i;
		b[rb[i].second]=i;
		bm[rb[i].second]=j;
	}

	//reset arrays
	for(int i=0;i<M;++i)
		while(i!=lb[i].second)
			std::swap(lb[i], lb[lb[i].second]);
	for(int i=0;i<M;++i)
		while(i!=rb[i].second)
			std::swap(rb[i], rb[rb[i].second]);

	for(int i=0, j=0;i<N;++i)
		if(q[i].t==1)
		{
			st.upd(1, 0, M, a[j], b[j]);
			++j;
		}
		else if(q[i].t==2)
		{
			st.upd(1, 0, M, a[q[i].a-1], -INF);
		}
		else if(q[i].t==3)
		{
			st.upd(1, 0, M, a[q[i].a-1], -INF);
			st.upd(1, 0, M, a[q[i].b-1], -INF);

			if(st.qry(1, 0, M, std::min(am[q[i].a-1], am[q[i].b-1]), M)<std::min(bm[q[i].a-1], bm[q[i].b-1]) && !bad(q[i].a, q[i].b))
				printf("YES\n");
			else
				printf("NO\n");

			st.upd(1, 0, M, a[q[i].a-1], b[q[i].a-1]);
			st.upd(1, 0, M, a[q[i].b-1], b[q[i].b-1]);
		}

	return 0;
}