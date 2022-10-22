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

int a[200005];
int Left[2];
int n, k;
bool last;

int play(int movesLeft){
	rep(i,0,n)
		Left[a[i]]++;
	if(Left[0] < 0 || Left[1] < 0)
		return 0;
	while(movesLeft > 1){
		movesLeft -= 2;
		if(Left[0] == 0){
			Left[1] -= 2;
		}
		else if(Left[1] == 0){
			Left[0] -= 2;
		}
		else{
			--Left[0];
			--Left[1];
		}
	}
	if(Left[0] && Left[1])
		return last;
	if(Left[0])--Left[0];
	if(Left[1])--Left[1];
	return Left[1]%2;
}

int main(){
	scanf("%d%d", &n, &k);
	int S=0;
	rep(i,0,n){
		scanf("%d", a+i);
		a[i]%=2;
		S+=a[i];
	}
	S%=2;
	if(k == n){
		puts((S%2)?"Stannis":"Daenerys");
		return 0;
	}
	int moves=(n-k);
	if(moves%2 == 0){
		last=0;
		Left[0]=0;
		Left[1]=-1;
		int x=0;
		if(play(moves-1))x=1;
		Left[0]=-1;
		Left[1]=0;
		if(play(moves-1))x=1;
		puts(x?"Stannis":"Daenerys");
	}
	else{
		last=1;
		puts(play(moves)?"Stannis":"Daenerys");
	}
}