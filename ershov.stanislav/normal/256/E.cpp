#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
int c[3][3], mod=777777777, n, m, x, y;
struct N {
	ll a[3][3];
	int l, r;
	N *L, *R;
	void upd() {
		memset(a, 0, sizeof(a));
		for (int i=0; i<3; i++) for (int j=0; j<3; j++) if (c[i][j])
			for (int k=0; k<3; k++) for (int l=0; l<3; l++) a[k][l]=(a[k][l]+L->a[k][i]*R->a[j][l])%mod;
	}
	void make(int k) {
		memset(a, 0, sizeof(a));
		if (k) a[k-1][k-1]=1;
		else for (int i=0; i<3; i++) a[i][i]=1;
	}
	N* build(int l, int r) {
		this->l=l; this->r=r;
		if (l==r) make(0);
		else {
			int mid=(l+r)/2;
			L=(new N())->build(l, mid);
			R=(new N())->build(mid+1, r);
			upd();
		}
		return this;
	}
	void change(int i, int k) {
		if (l==r) make(k); else {
			int mid=(l+r)/2;
			if (i>mid) R->change(i, k); else L->change(i, k);
			upd();
		}
	}
	int cnt() {
		int res=0;
		for (int i=0; i<3; i++) for (int j=0; j<3; j++) res=(res+a[i][j])%mod;
		return res;
	}
};
int main(){
	cin >> n >> m;
	for (int i=0; i<3; i++) for (int j=0; j<3; j++) cin >> c[i][j];
	N *r = (new N())->build(1, n);
	for (int i=0; i<m; i++) {
		cin >> x >> y;
		r->change(x, y);
		cout << r->cnt() << endl;
	}
    return 0;
}