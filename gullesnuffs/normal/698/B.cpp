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
vector<int> parents;
int root=-1;
bool vis[200005];

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", a+i);
		--a[i];
	}
	rep(i,0,n){
		set<int> S;
		int j=i;
		S.insert(i);
		if(vis[i])
			continue;
		while(true){
			vis[j]=true;
			j=a[j];
			if(S.count(j)){
				parents.push_back(j);
				if(a[j] == j)
					root=j;
			}
			S.insert(j);
			if(vis[j])
				break;
		}
	}
	if(root == -1){
		root=parents[0];
		printf("%d\n", (int)parents.size());
	}
	else{
		printf("%d\n", (int)parents.size()-1);
	}
	rep(i,0,parents.size())
		a[parents[i]]=root;
	rep(i,0,n)
		printf("%d ", a[i]+1);
	printf("\n");
}