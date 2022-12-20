#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
using namespace std;
typedef long long lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
double eps=1e-8;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define shl(i)      ((lld)1 << (i))
#define MP make_pair
#define PB push_back

const int N = 210000;
struct NODE{
	//point number, sum of x, ans
	lld cnt, sum, ans;
	NODE(lld cnt=0, lld sum=0, lld ans=0):cnt(cnt), sum(sum), ans(ans){}
	NODE operator+(const NODE &b) const{
		return NODE(cnt+b.cnt, sum+b.sum, b.sum * cnt - sum * b.cnt + b.ans + ans);
	}
}tree[N<<2];
lld sum[N];
void update(int rt, int l, int r, int p, int v){
	if (l == r){
		tree[rt].cnt += v;
		tree[rt].sum += v * sum[p];
		return;
	}
	int m = (l + r) / 2;
	if (p <= m) update(rt<<1, l, m, p, v);
	else update(rt<<1|1, m+1, r, p, v);
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

NODE query(int rt, int l, int r, int L, int R){
	if (L <= l && r <= R){
		return tree[rt];
	}
	if (R < l || r < L) return NODE(0, 0, 0);
	int m = (l + r) / 2;
	NODE tmp = query(rt<<1, l, m, L, R) + query(rt<<1|1, m+1, r, L, R);
	//cout << l << ',' << r << ',' << tmp.cnt << ',' << tmp.sum << ',' << tmp.ans << endl;
	return tmp;
}

lld in[N][3];
lld a[N], b[N];
map<lld, int> mp;
int main(){
	int n, m;
	cin >> n;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		b[i] = a[i];
		mp[a[i]] = 0;
	}
	cin >> m;
	for (int i=0; i<m; ++i){
		cin >> in[i][0] >> in[i][1] >> in[i][2];
		//scanf("%d%d%d", &in[i][0], &in[i][1], &in[i][2]);
		if (in[i][0] == 1){
			b[in[i][1]] += in[i][2];
			mp[b[in[i][1]]] = 0;
		}
	}
	int point = 0, size = mp.size();
	for (map<lld, int>::iterator it=mp.begin(); it!=mp.end(); ++it){
		it->second = ++ point;
		sum[it->second] = it->first;
		//update(1, 1, size, point, 0);
	}
	sum[point+1] = lldmax;
	for (int i=1; i<=n; ++i){
		b[i] = a[i];
		update(1, 1, point, mp[a[i]], 1);
	}
	int L, R;
	for (int i=0; i<m; ++i){
		if (in[i][0] == 1){
			update(1, 1, point, mp[b[in[i][1]]], -1);
			b[in[i][1]] += in[i][2];
			update(1, 1, point, mp[b[in[i][1]]], 1);
		}else {
			L = lower_bound(sum+1, sum+1+point, in[i][1]) - sum;
			R = upper_bound(sum+1, sum+1+point, in[i][2]) - sum - 1;
			if (R <= L){
				cout << "0" << endl;
			}else {
				//NODE tmp = query(1, 1, point, L, R);
				//cout << tmp.cnt << ' ' << tmp.ans << endl;
				cout << query(1, 1, point, L, R).ans << endl;
			}
		}
	}
	return 0;
}