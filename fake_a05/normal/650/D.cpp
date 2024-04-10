#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
#define endl '\n'

const int maxN = 8e5 + 5, mod = 1e9 + 7;
#define int long long
int N, Q;
int arr[maxN];
vector<ii> allH;
vector<pair<ii, int> > allQ;
int trueVal[maxN];
int lis[maxN], lisNum[maxN], lds[maxN], ldsNum[maxN];
vector<ii> Qu[maxN];
int ans[maxN];
int allLIS, LIS;
struct it // x = k, getMax(l, r)
{
	vector<ii> mx = vector<ii> (4 * maxN, {0, 0});
	#define mid (l + r) / 2
	#define lc 2 * i, l, mid
	#define rc 2 * i + 1, mid + 1, r
	it(){
	}
	void as(int i, int l, int r, int pos, int val, int num)
	{
		assert(i < mx.size());
		if(l > pos or pos > r) return;
		if(l == r)
		{
			mx[i] = {val, num};
		}	
		else
		{
			as(lc, pos, val, num);
			as(rc, pos, val, num);
			if(mx[2 * i].fi == mx[2 * i + 1].fi)
			{
				mx[i] = {mx[2 * i].fi, (mx[2 * i].se + mx[2 * i + 1].se) % mod};
			}
			else
			{
				mx[i] = max(mx[2 * i], mx[2 * i + 1]);
			}
		}
	}	
	ii gMax(int i, int l, int r, int ll, int rr)
	{
		assert(i < mx.size());
		if(l > rr or ll > r) return {0, 0};
		if(ll <= l and r <= rr) return mx[i];
		ii L = gMax(lc, ll, rr), R = gMax(rc, ll, rr);
		ii re = (L.fi == R.fi? make_pair(L.fi, (L.se + R.se) % mod): max(L, R));
		return re;
	}
} pref, suf;

void proc()
{
	pref = suf = it();
	loop(i, 1, N)
	{
		suf.as(1, 1, N + Q, trueVal[i], lds[i], 0);
	}
	loop(i, 1, N)
	{
		if(i > 1) pref.as(1, 1, N + Q, trueVal[i - 1], lis[i - 1], 0);
		suf.as(1, 1, N + Q, trueVal[i], 0, 0);
		int iLis = lis[i] + lds[i] - 1 == LIS? (lisNum[i] * ldsNum[i]) % mod: 0;
		for(ii t: Qu[i])
		{
			int is = (pref.gMax(1, 1, N + Q, 1, t.fi - 1)).fi, ds = (suf.gMax(1, 1, N + Q, t.fi + 1, N + Q)).fi;
			if(is + ds + 1 >= LIS) 
			{
				ans[t.se] = is + ds + 1;
			}
			else if(iLis != allLIS) ans[t.se] = LIS;
			else  ans[t.se] = LIS - 1;
		}
	}
}

void getLis()
{
	loop(i, 1, N)
	{
		ii 	t = pref.gMax(1, 1, N + Q, 1, trueVal[i] - 1);
		if(t.fi == 0) 
		{
			lis[i] = lisNum[i] = 1;
		}
		else
		{
//			cout << i << endl;
			lis[i] = t.fi + 1;
			lisNum[i] = t.se;
//			if(t.se == 0) cout << i << sp << t.fi << endl;
		}
		pref.as(1, 1, N + Q, trueVal[i], lis[i], lisNum[i]);
		if(LIS < lis[i])
		{
			LIS = lis[i];
			allLIS = lisNum[i];
		}
		else if(LIS == lis[i]) allLIS = (allLIS + lisNum[i]) % mod;
	}
}

void getLds()
{
	rloop(i, N, 1)
	{
		ii 	t = suf.gMax(1, 1, N + Q, trueVal[i] + 1, N + Q);
		if(t.fi == 0)
		{
			lds[i] = ldsNum[i] = 1;
		}
		else
		{
			lds[i] = t.fi + 1;
			ldsNum[i] = t.se;
		}
		suf.as(1, 1, N + Q, trueVal[i], lds[i], ldsNum[i]);	
	}
}
bool cmp(const ii &a, const ii &b)
{
	if(a.fi == b.fi) return a.se > b.se;
	return a.fi < b.fi;
}
int getT(ii a)
{
	return lower_bound(all(allH), a, cmp) - begin(allH) + 1;
}
void conv()
{
	sort(all(allH), cmp);
	loop(i, 1, N)
	{
		trueVal[i] = getT({arr[i], i});
	}
	for(auto t: allQ)
	{
		int T = getT(t.fi); // {value, pos}, id
		Qu[t.fi.se].eb({T, t.se});
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	loop(i, 1, N)
	{
		cin >> arr[i];
		allH.eb({arr[i], i});
	}
	loop(id, 1, Q)
	{
		int pos, val;
		cin >> pos >> val;
		allQ.eb({{val, pos}, id});
		allH.eb({val, pos});
	}
	conv();
	getLis();
//	if(N == 400000 and Q == 1) cout << LIS << "|||" << allLIS << "\n";
	getLds();
	proc();
	loop(id, 1, Q) cout << ans[id] << endl;
}