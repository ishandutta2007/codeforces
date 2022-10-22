#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int tree[1000005][20];
int tree2[2200005][20];
int L[100005],R[100005],Q[100005];
int A[100005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,m){
		int l,r,q;
		scanf("%d%d%d", &l, &r, &q);
		L[i]=l;R[i]=r;Q[i]=q;
		--l;
		rep(j,0,20){
			if(l == r)
				break;
			assert(l < r);
			tree[l][j]|=q;
			l=(l+1)/2;
			if(r%2){
				tree[r-1][j]|=q;
			}
			r/=2;
		}
	}
	rep(i,0,n){
		A[i]=0;
		rep(j,0,20){
			A[i]|=tree[i/(1<<j)][j];
		}
		assert(A[i] < (1<<30));
		tree2[i][0]=A[i];
	}
	rep(j,1,20){
		rep(i,0,n){
			tree2[i][j]=(tree2[i][j-1]&tree2[i+(1<<(j-1))][j-1]);
		}
	}
	rep(i,0,m){
		int l=L[i],r=R[i],q=Q[i];
		long long a=(1LL<<31)-1;
		--l;
		rep(j,0,20){
			if(l == r)
				break;
			assert(l<r);
			a&=tree2[l*(1<<j)][j];
			//a&=tree[l][j];
			l=(l+1)/2;
			if(r%2){
				a&=tree2[(r-1)*(1<<j)][j];
				//a&=tree[r-1][j];
			}
			r/=2;
		}
		if(a != q){
			assert(a > q);
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	rep(i,0,n)
		printf("%d ", A[i]);
	printf("\n");
}