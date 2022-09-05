#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MAXN = 100001; //check the limits, dummy
const int SZ = 1048576;
const int MINVAL = -100000000;
int maxPrice = 0;
int minPrice = 1000000;

ll mx[2*SZ], lazy[2*SZ]; //Lazy segtree implementation inspired by bqi343's Github contributions

void push(int index, ll L, ll R) {
    mx[index] += lazy[index];
    if (L != R) lazy[2*index] += lazy[index], lazy[2*index+1] += lazy[index];
    lazy[index] = 0;
}

void pull(int index) {
    mx[index] = max(mx[2*index], mx[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return 0;
    if (lo <= L && R <= hi) return mx[index];

    int M = (L+R) / 2;
    return max(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int getRes() {
    int lo = minPrice;
    int hi = maxPrice;
    ll init = query(lo, hi);
    if (init <= 0) return -1;
    F0R(i, 25) {
        if (hi-lo <= 1) break;
        int mid = (lo+hi)/2;
        ll cur = query(mid, SZ-1);
        if (cur > 0) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    if (query(hi, SZ-1) > 0) return hi;
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    F0R(i, 2*SZ) {
        mx[i] = 0; lazy[i] = 0;
    }

    int N, M; //cin >> N >> M;
    scanf("%d %d", &N, &M);
   // N = 300000; M = 300000;
    int price[N];
    //map<int, int> activePrices;
    F0R(i, N) {
        scanf("%d", &price[i]);
       // price[i] = 1000000;
        maxPrice = max(maxPrice, price[i]);
        minPrice = min(minPrice, price[i]);
        /*if (activePrices.count(price[i])) {
            activePrices[price[i]]++;
        } else {
            activePrices.insert(mp(price[i], 1));
            //update(prices[i], prices[i], -1 * query(prices[i], prices[i]));
        }*/
    }

    int money[M];
    F0R(i, M) {
        scanf("%d", &money[i]);
        //money[i] = 999999;
        maxPrice = max(maxPrice, money[i]);
        minPrice = min(minPrice, money[i]);
    }

    F0R(i, N) {
        update(0, price[i], 1);
    }
    F0R(i, M) {
        update(0, money[i], -1);
    }

    /*F0R(i, 100) {
        cout << i << " " << query(i, i) << endl;
        cout << query(i, SZ-1) << endl;
    }
    cout << query(0, 100) << endl;*/

    int Q; scanf("%d", &Q);
    //Q = 300000;
    int last = getRes();
    F0R(i, Q) {
        int type; scanf("%d", &type);
        //type = 1;
        if (type == 2) {
            int stu, newPrice; //cin >> stu >> newPrice;
            scanf("%d %d", &stu, &newPrice);
            //stu = i+1; newPrice = 999999;
            maxPrice = max(maxPrice, newPrice);
            minPrice = min(minPrice, newPrice);
            stu--;
            if (money[stu] < newPrice) {
                update(money[stu]+1, newPrice, -1);
            } else {
                update(newPrice+1, money[stu], 1);
            }
            //update(0, money[stu], 1);
            //update(0, newPrice, -1);
            int oldPrice = money[stu];
            money[stu] = newPrice;
            if ((oldPrice < last && newPrice < last) || oldPrice == newPrice) {
                printf("%d\n", last);
            } else {
                last = getRes();
                printf("%d\n", last);
            }

            //cout << getRes() << endl;
        } else {
            int dish, newPrice; //cin >> dish >> newPrice;
            scanf("%d %d", &dish, &newPrice);
            //dish = i+1; newPrice = 999999;
            maxPrice = max(maxPrice, newPrice);
            minPrice = min(minPrice, newPrice);
            dish--;
            int oldPrice = price[dish];
            //activePrices[oldPrice]--;
            //update(0, oldPrice, -1);
            /*if (activePrices[oldPrice] == 0) {
                //activePrices.erase(oldPrice);
                //update(oldPrice, oldPrice, MINVAL - query(oldPrice, oldPrice));
                //deactivate oldPrice
            }*/
            price[dish] = newPrice;
            /*if (!activePrices.count(newPrice)) {
                //activePrices.insert(mp(newPrice, 0));
                ll nextVal;
                update(oldPrice, oldPrice, )
                //activate newPrice
            }*/
            //update(0, newPrice, 1);
            if (oldPrice < newPrice) {
                update(oldPrice+1, newPrice, 1);
            } else {
                update(newPrice+1, oldPrice, -1);
            }
            //activePrices[newPrice]++;
            if ((oldPrice < last && newPrice < last) || oldPrice == newPrice) {
                printf("%d\n", last);
            } else {
                last = getRes();
                printf("%d\n", last);
            }
            //cout << getRes() << endl;
        }

        /*if (i == 1) {
            F0R(i, 100) {
                cout << i << " " << query(i, i) << endl;
                cout << query(i, SZ-1) << endl;
            }
            cout << query(0, 100) << endl;
        }*/
    }



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343