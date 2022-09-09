#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int maxa = 1e2;
const int MAXA = maxa + 5;

template<typename T>
struct Deque
{
	T q[MAXN];
	int head, tail;
	Deque(void){ clear();}
	inline void clear(void){ head=1; tail=0;}
	inline bool empty(void) const { return head > tail;}
	inline int size(void) const { return tail - head + 1;}
	
	inline T& front(void){ return q[head];}
	inline T front(void) const { return q[head];}
	inline T& back(void){ return q[tail];}
	inline T back(void) const { return q[tail];}
	
	inline void push_back(const T x){ q[++tail] = x;}
	inline void pop_back(void){ --tail;}
	inline void pop_front(void){ ++head;}
	
	inline T& operator [] (const int x){ return *(q + head + x);}
	inline T operator [] (const int x) const { return *(q + head + x);}
};

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int freq[MAXA];
	for(int i=1; i<=n; ++i) ++freq[a[i]];
	
	int mx=0, mxcnt=0, mxk = 0;
	for(int i=1; i<=maxa; ++i)
	{
		if(freq[i] > mx) mx = freq[i], mxcnt = 0;
		if(freq[i] == mx) ++mxcnt, mxk = i;
	}
	if(mxcnt > 1) return printf("%d",n), 0;
	if(mx == n) return printf("0"), 0;
	
	int ans = 0;
	for(int k=1; k<=maxa; ++k) if(k != mxk)
	{
		static int suf[MAXN];
		suf[n+1] = 0;
		for(int i=n; i>=1; --i)
		{
			suf[i] = suf[i+1];
			if(a[i] == mxk) ++suf[i];
			if(a[i] == k) --suf[i];
		}
		
		static Deque<pii> q;
		q.clear();
		for(int i=1; i<=n+1; ++i)
		{
			while(!q.empty() && q.back().first <= suf[i]) q.pop_back();
			q.push_back(make_pair(suf[i], i));
		}
		
//		printf("\nk: %d\n",k);
//		for(int i=0; i<(int)q.size(); ++i)
//			printf("q[%d]: %d %d\n",i,q[i].first,q[i].second);
		
		int need = mx - freq[k];
		
		int cur = 0;
		for(int i=0; i<=n; ++i)
		{
			if(i)
			{
				if(a[i] == mxk) ++cur;
				if(a[i] == k) --cur;
			}
			while(!q.empty() && q.front().second <= i) q.pop_front();
			while(!q.empty() && q.front().first + cur > need) q.pop_front();
			if(q.empty()) break;
			
			if(q.front().first + cur == need)
				ans = max(ans, n - i - (n - q.front().second + 1));
		}
	}
	
	printf("%d",ans);
	return 0;
}