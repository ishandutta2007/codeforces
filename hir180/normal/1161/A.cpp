#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k;
bool used[100005];
vector<int>pos[100005];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		int a; scanf("%d",&a);
		used[a] = 1;
		pos[a].pb(i);
	}
	int ans = 0;
	for(int i=1;i<=n;i++) if(!used[i]) ans++;
	for(int i=1;i<=n;i++){
		for(int j=-1;j<=1;j+=2){
			int x = i, y = i+j;
			if(1 <= y && y <= n){
				if(used[x] && pos[y].size() && pos[x][0] < pos[y][pos[y].size()-1]){
				}
				else{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}