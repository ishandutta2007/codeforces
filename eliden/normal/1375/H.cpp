#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int n;
vector<int> inv;
int cnt;
vector<int> u, v;

struct Tree {
	int lo, hi;
	Tree *bot, *top;
	vector<int> numdwn;
    unordered_map<ll,int> mp;
	// range [l,r), values in [x,y]
	Tree(int *l, int *r,int x, int y) {
		lo=x, hi=y;
		if(lo==hi || l>=r) return;
		int mid = (lo+hi)/2, cntdwn=0;
		numdwn.reserve(r-l);
		for(int *p=l;p!=r;++p) {
			if(*p<=mid) ++cntdwn;				
			numdwn.push_back(cntdwn);
		}
		int *divider = stable_partition(l,r,[mid](int v){return v<=mid;});
		bot = new Tree(l,divider,lo,mid);
		top = new Tree(divider,r,mid+1,hi);
	}
    // query in [l,r]
    int idof(int l, int r) {
        if(l>r) return -1;
        if(lo==hi) return inv[lo];

        ll code = ((ll)l)*n+r;
        if(mp.count(code)) return mp[code];
        
        int numbl = 0;
		if(l>0)	numbl = numdwn[l-1];
		int numbr=numdwn[r], numb=numbr-numbl;

        int botid = bot->idof(numbl,numbr-1);
	    int topid = top->idof(l-numbl,r-numbr);
        int ans = -1;
        if(botid==-1) ans = topid;
        else if(topid==-1) ans = botid;
        else {
            ans = cnt++;
            u.push_back(botid);
            v.push_back(topid);
        }
        mp[code] = ans;
        return ans;
    }
	// // kth smallest in [l,r]
	// int kth(int l, int r, int k) {
	// 	if(l>r) return -1;
	// 	if(lo==hi) return lo;
	// 	int numbl = 0;
	// 	if(l>0)	numbl = numdwn[l-1];
	// 	int numbr=numdwn[r], numb=numbr-numbl;
	// 	if(k<=numb) return bot->kth(numbl,numbr-1,k);
	// 	else return top->kth(l-numbl,r-numbr,k-numb);
	// }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>n>>q;
    vector<int> a(n);
    rep(i,0,n) {
        cin>>a[i];
        --a[i];
    }
    inv.resize(n);
    rep(i,0,n) inv[a[i]]=i;
    auto acopy = a;
    cnt = n;
    Tree tree(&acopy[0], &acopy[0]+n, 0, n-1);
    
    vector<int> lq(q), rq(q);
    rep(i,0,q) {
        cin>>lq[i]>>rq[i];
        --lq[i];
        --rq[i];
    }
    vector<int> ks(q);
    rep(i,0,q) {
        ks[i] = tree.idof(lq[i],rq[i]);
        //debug(ks[i]);
    }
    cout<<cnt<<"\n";
    rep(i,0,sz(u)) {
        cout<<u[i]+1<<" "<<v[i]+1<<"\n";
    }
    rep(i,0,q) cout<<ks[i]+1<<" ";
    cout<<"\n";
}