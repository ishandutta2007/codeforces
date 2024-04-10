#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define th third

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(0, std::numeric_limits<int>::max() - 1);

using namespace std;

ll n, k;
ll a[100001], pr[100001];
struct node;

vector<node> vv;

struct node {
    ll balance;
    ll x;
    ll amount;
    node* left;
    node* right;
    node() : x(0), balance(distrib(gen)), left(nullptr), right(nullptr), amount(1) {};
    node(ll x) : x(x), balance(distrib(gen)), left(nullptr), right(nullptr), amount(1) {};

    void upd() {
        amount = (left ? left->amount : 0) + 1 + (right ? right->amount : 0);
    }
};

struct dd_map {

    node* root{nullptr};

    ~dd_map() {}

    void insert(node* p) {
        if (!root) {
            root = p;
            return;
        }
        auto [lft, rgt] = split(root, p->x);
        root = merge(merge(lft, p), rgt);
    }

    void dump(node *u) {
        if (!u) return;
        dump(u->left);
        cout << u->x << " ";
        dump(u->right);
    }


    node* merge(node* L, node* R) {
        if (!L) return R;
        if (!R) return L;
        if (L->balance < R->balance) {
            R->left = merge(L, R->left);
            R->upd();
            return R;
        } else {
            L->right = merge(L->right, R);
            L->upd();
            return L;
        }
    }

    pair<node*, node*> split(node* root, ll x) {
        if (!root) return mp(nullptr, nullptr);
        if (root->x <= x) {
            auto [tl, tr] = split(root->right, x);
            root->right = tl;
            root->upd();
            return {root, tr};
        } else {
            auto [tl, tr] = split(root->left, x);
            root->left = tr;
            root->upd();
            return {tl, root};
        }
    }

    ll amount_less_or_equal(ll x) {
        auto [lft, rgt] = split(root, x);
        ll ans = (lft ? lft->amount : 0);
        root = merge(lft, rgt);
        return ans;
    }
};

ll solve(ll sum) {
    dd_map dd;
    for (size_t i = 0; i <= n; i++) {
        vv[i].left = 0;
        vv[i].right = 0;
        vv[i].amount = 1;
    }
    dd.insert(&vv[0]);
    ll ans = 0;
    for (size_t i = 1; i <= n; i++) {
        ll oo = dd.amount_less_or_equal(pr[i] - sum);
        ans += oo;
        dd.insert(&vv[i]);
    }
    return ans;
}

int main() {
    cin >> n >> k;
    pr[0] = 0;
    vv.push_back(node(0));
    ll mn = 0, mx = 0;
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
        vv.push_back(node(pr[i]));
        if (mn > pr[i]) mn = pr[i];
        if (mx < pr[i]) mx = pr[i];
    }

    ll l = -1e14, r = 1e14;
    while (l < r) {
        ll w = (l + r + 1) / 2;
        if (solve(w) < k) {
            r = w - 1;
        } else {
            l = w;
        }
    }
    cout << l << "\n";
    return 0;
}