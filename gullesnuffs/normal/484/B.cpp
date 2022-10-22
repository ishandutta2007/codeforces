#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int a[200005];
bool used[2000005];
vector<int> b;
int pre[2000005];

int main(){
	int n;
	scanf("%d", &n);
	rep(i, 0, n){
		scanf("%d", a+i);
		used[a[i]]=1;
	}
	for(int i=0; i <= 1000000; ++i)
		if(used[i]){
			b.push_back(i);
		}
	pre[0]=0;
	for(int i=1; i <= 2000000; ++i){
		if(used[i-1])
			pre[i]=i-1;
		else
			pre[i]=pre[i-1];
	}
	int ans=0;
	for(int i=0; i < b.size(); ++i){
		for(int j=b[i]; j <= 1000000; j += b[i]){
			/*auto it=B.lower_bound(j+b[i]);
			--it;
			int k=*it;*/
			int k=pre[j+b[i]];
			ans=max(k-j, ans);
		}
	}
	printf("%d\n", ans);
	/*for(int i=1000000; i >= 0; --i){
		for(int j=b.size()-1; j >= 0 && b[j] > i; --j){
			for(int k=i+b[j]; k <= 1000000; k += b[j])
				if(used[k]){
					printf("%d\n", i);
					return 0;
				}
		}
	}*/
}