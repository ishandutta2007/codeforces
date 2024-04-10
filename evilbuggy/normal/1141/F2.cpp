#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const int maxn = 1505;

int dp[maxn][maxn];
ll a[maxn], sa[maxn];
pair<int, int> p[maxn][maxn];
map<ll, pair<int, int> > mem;

int main(){

#ifndef  ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n;
    cin>>n;
    sa[0] = 0;
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	sa[i] = sa[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++){
    	for(int j = i; j <= n; j++){
    		ll sum = sa[j] - sa[i-1];
    		if(mem.find(sum) == mem.end()){
    			dp[i][j] = 1;
    			p[i][j] = {-1, -1};
    		}else{
    			int l = mem[sum].first;
    			int r = mem[sum].second;
    			dp[i][j] = dp[l][r] + 1;
    			p[i][j] = mem[sum];
    		}
    	}
    	for(int j = 1; j <= i; j++){
    		ll sum = sa[i] - sa[j-1];
    		if(mem.find(sum) == mem.end()){
    			mem[sum] = {j, i};
    		}else if(mem[sum].first < j){
    			mem[sum] = {j, i};
    		}
    	}
    }
    int x = 1, y = 1;
    for(int i = 1; i <= n; i++){
    	for(int j = i; j <= n; j++){
    		if(dp[x][y] < dp[i][j]){
    			x = i;
    			y = j;
    		}
    	}
    }
    cout<<dp[x][y]<<endl;
    while(x != -1){
    	cout<<x<<" "<<y<<endl;
    	int nx = p[x][y].first;
    	int ny = p[x][y].second;
    	x = nx;
    	y = ny;
    }
}