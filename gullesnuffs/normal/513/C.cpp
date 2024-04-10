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

int l[6],r[6],len[6];
double L[6],R[6];
double prob[10005];
	int n;

double getProbLarger(int i, int val){
	if(val > r[i])
		return 0;
	if(val < l[i])
		return 1;
	return (r[i]-val)/(R[i]-L[i]+1);
}

double getProbEqual(int i, int val){
	if(val > r[i])
		return 0;
	if(val < l[i])
		return 0;
	return 1/(R[i]-L[i]+1);	
}

double getProbSmaller(int i, int val){
	return 1-getProbLarger(i,val)-getProbEqual(i,val);
}


int main(){
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d%d", l+i, r+i);
		len[i]=r[i]-l[i];
		L[i]=l[i];
		R[i]=r[i];
	}
	double sum=0;
	double ans=0;
	rep(i,0,10003){
		rep(j,0,n){
			rep(k,0,n){
				if(k == j)
					continue;
				double p=1;
				p *= getProbLarger(j,i);
				p *= getProbEqual(k,i);
				rep(l,0,n){
					if(l == j || l == k)
						continue;
					if(l < k)
						p *= getProbSmaller(l,i);
					else
						p *= 1-getProbLarger(l,i);
				}
				ans += p*i;
				if(k < j)
					continue;
				p=1;
				p *= getProbEqual(j,i);
				p *= getProbEqual(k,i);
				rep(l,0,n){
					if(l == j || l == k)
						continue;
					if(l < k)
						p *= getProbSmaller(l,i);
					else
						p *= 1-getProbLarger(l,i);
				}
				ans += p*i;
			}
		}
	}
	printf("%.10lf\n", ans);
}