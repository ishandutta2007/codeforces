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
char s[200000];

int main(){
	scanf("%s", s);
	int ans=0;
	bool any=0;
	int len=strlen(s);
	for(int i=0; i < len; ++i){
		if((s[i]-'0')%2)
			continue;
		any=1;
		ans=i;
		if(s[i] < s[len-1])
			break;
	}
	swap(s[ans], s[len-1]);
	if(any)
		cout << string(s) << endl;
	else
		printf("-1\n");
}