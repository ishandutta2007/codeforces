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
	int a, b;
	cin>>a>>b;
	forint(x1, -a, a) forint(y1, -a, a)
		if(x1*x1+y1*y1==a*a) {
			if(x1==0 || y1==0) continue;
			double x=x1, y=y1;
			x=x/double(a)*double(b);
			y=y/double(a)*double(b);
			swap(x, y), y=-y;
			int x0=int(x), y0=int(y);
			forint(x2, x0-3, x0+3) forint(y2, y0-3, y0+3)
				if(x2*x2+y2*y2==b*b) {
					if(x2==0 || y2==0) continue;
					if(x1==x2 || y1==y2) continue;
					if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)!=a*a+b*b) continue;
					cout<<"YES"<<endl;
					cout<<"0 0"<<endl;
					cout<<x1<<" "<<y1<<endl;
					cout<<x2<<" "<<y2<<endl;
					return 0;
				}
		}
	cout<<"NO"<<endl;
	return 0;
}