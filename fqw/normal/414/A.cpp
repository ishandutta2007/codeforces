#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPI;
#define MP make_pair
#define PB push_back
#define fi first
#define se second

int main() {
	int n, k;
	cin>>n>>k;
	if(n==1) {
		if(k==0) cout<<1<<endl;
		else cout<<-1<<endl;
	} else {
		int m=n/2;
		if(k<m) cout<<-1<<endl;
		else {
			cout<<k-m+1<<" "<<2*(k-m+1)<<" ";
			int t=2*(k-m+1)+1;
			forint(i, 2, m) {
				cout<<(++t)<<" ";
				cout<<(++t)<<" ";
			}
			if(n%2==1) cout<<(++t)<<" ";
			cout<<endl;
		}
	}
	return 0;
}