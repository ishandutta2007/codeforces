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

char s[100005];

int main(){
	scanf("%s", s);
	bool started=false;
	for(int i=0; s[i]; ++i){
		if(s[i] != 'a'){
			s[i] -= 1;
			started=true;
		}
		else{
			if(started)
				break;
		}
	}
	if(!started)
		s[strlen(s)-1] = 'z';
	printf("%s\n", s);
}