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

int count(){
	int ret=0;
	char last=0;
	for(int i=0; s[i]; ++i){
		if(s[i] != last){
			++ret;
			last=s[i];
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int pos1=0;
	int pos2=n;
	int ans=count();
	for(int i=0; s[i+1]; ++i){
		if(s[i] == s[i+1]){
			pos1=i+1;
			rep(j,pos1,pos2){
				if(s[j] == '0')
					s[j]='1';
				else
					s[j]='0';
			}
			ans=max(ans, count());
			rep(j,pos1,pos2){
				if(s[j] == '0')
					s[j]='1';
				else
					s[j]='0';
			}
			break;
		}
	}
	for(int i=n-2; i >= 0; --i){
		if(s[i] == s[i+1]){
			pos2=i+1;
			break;
		}
	}
	rep(i,pos1,pos2){
		if(s[i] == '0')
			s[i]='1';
		else
			s[i]='0';
	}
	ans=max(ans, count());
	printf("%d\n", ans);
}