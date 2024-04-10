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

int main(){
	int n;
	scanf("%d", &n);
	int x;
	rep(i,0,n){
		int a;
		scanf("%d", &a);
		while(a%2 == 0)a/=2;
		while(a%3 == 0)a/=3;
		if(i){
			if(a != x){
				puts("No");
				return 0;
			}
		}
		else
			x=a;
	}
	puts("Yes");
}