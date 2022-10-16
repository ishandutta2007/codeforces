#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty;
    vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

int n;
int a[110000];
map<int, int> la;
int max_L[110000];
int max_R[110000];
const int mod = 1000000007;


long long S(int l, int r) {
	l--;
	return (r * 1ll * (r+1))/2 - (l * 1ll * (l+1))/2;
}

struct node {
	int l_idx, r_idx;
	int sumR, sumL, sumLR, sumRle;
	int maxL, minR;

	node operator+(const node& ot) {
		node ret;
		ret.sumR = (sumR + ot.sumR) % mod;
		ret.sumL = (sumL + ot.sumL) % mod;
		ret.sumLR = (sumLR + ot.sumLR) % mod;
		ret.sumRle = (sumRle + ot.sumRle) % mod;
		ret.maxL = max(maxL, ot.maxL);
		ret.minR = min(minR, ot.minR);
		ret.l_idx = min(l_idx, ot.l_idx);
		ret.r_idx = max(r_idx, ot.r_idx);
		return ret;
	}
};


struct update {
	int L, R;

	update() {L = R = -1;}

	node operator()(const node& n) {
		node ret = n;

		int r_idx = n.r_idx, l_idx = n.l_idx;

		if (L != -1) {
			ret.sumL = (L * 1ll * (r_idx - l_idx + 1)) % mod;
			ret.sumLR = (ret.sumR * 1ll * L) % mod;
			ret.maxL = L;
		}

		if (R != -1) {
			ret.sumR = (R * 1ll * (r_idx - l_idx + 1)) % mod;
			ret.sumLR = (ret.sumL * 1ll * R) % mod;
			ret.sumRle = (R * 1ll * S(l_idx, r_idx)) % mod;
			ret.minR = R;
		}

		return ret;
	}

	update operator+(const update& ot) {
		update ret = ot;
		if (ret.L == -1 || ret.L < L) ret.L = L;
		if (ret.R == -1 || (ret.R > R && R != -1)) ret.R = R;
		return ret;
	}
};

node zero;

long long divide(int l, int r) {
	bool dbg = false;
	if (l > r) return 0;
	
	int md = (l+r)/2;
	int els = md - l + 1;
	seg_tree_lazy<node, update> st(els, zero);
	
	vector<node> leaves(els, zero);

	vector<int> origR(els);
	vector<int> origL(els);

	int curR = n;
	int curL = 1;
	for (int i = md; i >= l; i--) {
		curR = min(curR, max_R[i]);
		curL = max(curL, max_L[i]);
		origR[i-l] = curR;
		origL[i-l] = curL;

		node ret;
		ret.sumR = ret.minR = curR;
		ret.sumL = ret.maxL = curL;
		ret.sumLR = (curR * 1ll * curL) % mod;
		ret.sumRle = (curR * 1ll * i) % mod;
		ret.l_idx = ret.r_idx = i;
		leaves[i-l] = ret;
	}
	st.set_leaves(leaves);

	long long ans = 0;

	
	for (int re = md; re <= r; re++) {
		int cur_L = max_L[re];

		int sm = lower_bound(origL.rbegin(), origL.rend(), cur_L) - origL.rbegin();
		sm = l + (els - sm);
		update U;
		U.L = cur_L;
		if (sm != md+1 && st.query(sm-l,md-l).maxL < cur_L) st.upd(sm-l, md-l, U);

		int cur_R = max_R[re];
		sm = lower_bound(origR.begin(), origR.end(), cur_R) - origR.begin();
		sm += l;
		U.L = -1;
		U.R = cur_R;
		if (sm != md+1 && st.query(sm-l,md-l).minR > cur_R) st.upd(sm-l, md-l, U);

		sm = l; int bg = md+1;
		while (sm < bg) {
			int mmm = (sm+bg)/2;
			node n = st.query(mmm-l, md-l);
			if (n.minR >= re && n.maxL <= mmm) bg = mmm;
			else sm=mmm+1;
		}
		if (sm != md+1) {
			node n = st.query(sm-l, md-l);

			long long th = 0;
			th = (re * 1ll * n.sumL) % mod;
			th = (th - re * S(sm, md)) % mod;
			th = (th + n.sumRle) % mod;
			th = (th - n.sumLR) % mod;

			if (dbg) {
				printf("sumL = %lld sumRle = %lld sumLR = %lld sumR = %lld \n", n.sumL, n.sumRle, n.sumLR, n.sumR );
				printf("re = %d sm = %d th = %lld\n", re, sm, th);
			}
			ans = (ans + th) % mod;
		}
	}

	ans = (ans + divide(l, md-1)) % mod;
	ans = (ans + divide(md+1, r)) % mod;

	//printf("divide %d %d -> %lld\n", l, r, ans);
	return ans;
}


void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
    	max_L[i] = la[a[i]]+1;
    	la[a[i]] = i;
    }
    la.clear();

    for (int i = n; i >= 1; i--) {
    	int l = la[a[i]];
    	if (l == 0) max_R[i] = n;
    	else max_R[i] = la[a[i]]-1;
    	la[a[i]] = i;
    }
    la.clear();


	zero.l_idx = 10000000;
	zero.r_idx = -1;
	zero.maxL = 1;
	zero.minR = n;
	zero.sumR = zero.sumL = zero.sumLR = zero.sumRle = 0;

	long long ans = divide(1, n);
	ans=(ans+mod)%mod;
	printf("%lld\n", ans);
}


#include <fstream>


int main() {


    solve();
}