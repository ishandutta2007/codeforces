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

int p[1000000];
int q[1000000];
int posp;
int posq;
int posr[1000000];

struct Fenwick{
	int a[1000000];

	void update(int pos, int val){
		for(; pos < 1000000; pos|=pos+1)
			a[pos] += val;
	}

	int query(int pos){
		int ret=0;
		for(; pos >= 0; pos=(pos&(pos+1))-1)
			ret += a[pos];
		return ret;
	}
} fp, fq, fr;

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n)
		scanf("%d", p+i);
	rep(i,0,n)
		scanf("%d", q+i);
	int carry=0;
	rrep(i,n,0){
		posp=fp.query(p[i]);
		fp.update(p[i],1);		
		posq=fq.query(q[i]);
		fq.update(q[i],1);
		posr[i]=posp+posq+carry;
		if(posr[i] >= n-i){
			posr[i] -= (n-i);
			carry=1;
		}
		else
			carry=0;
	}
	rep(i,0,n){
		fr.update(i,1);
	}
	rep(i,0,n){
		int lo=-1, hi=n;
		while(hi-lo > 1){
			int mid=(lo+hi)/2;
			if(fr.query(mid) > posr[i])
				hi=mid;
			else
				lo=mid;
		}
		fr.update(hi, -1);
		printf("%d ", hi);
	}
	printf("\n");
}