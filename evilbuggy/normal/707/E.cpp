#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const int maxn = 2005;

ll f[maxn][maxn];

inline void update(int x, int y, ll k){
	while(x < maxn){
		int yy = y;
		while(yy < maxn){
			f[x][yy] += k;
			yy += yy&(-yy);
		}
		x += x&(-x);
	}
}

inline ll query(int x, int y){
	ll ans = 0;
	while(x > 0){
		int yy = y;
		while(yy > 0){
			ans += f[x][yy];
			yy &= (yy - 1);
		}
		x &= (x - 1);
	}
	return ans;
}

ll query(int x1, int y1, int x2, int y2){
	x1--; y1--;
	return query(x2, y2) + query(x1, y1) - query(x2, y1) - query(x1, y2);
}

struct Node{
	int t, i, qind;
};

struct Rect{
	int x1, y1, x2, y2;
};

Node narr[1000005];
vector<pair<pair<int, int>, int> > gar[maxn];
ll val[maxn][maxn];
Rect rarr[maxn];
bool swt[maxn];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++){
    	int len, x, y, w;
    	cin>>len;
    	while(len--){
    		cin>>x>>y>>w;
    		gar[i].push_back({{x, y}, w});
    	}
    	swt[i] = true;
    }
    int q, qind, ind, x1, y1, x2, y2;
    string s;
    cin>>q;
    qind = 0;
    for(int i = 1; i <= q; i++){
    	cin>>s;
    	if(s[0] == 'S'){
    		cin>>ind;
    		narr[i] = {0, ind, 0};
    	}else{
    		++qind;
    		cin>>x1>>y1>>x2>>y2;
    		narr[i] = {1, 0, qind};
    		rarr[qind] = {x1, y1, x2, y2};
    	}
    }
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= k; i++){
    	for(auto x : gar[i]){
    		update(x.first.first, x.first.second, x.second);
    	}
    	for(int j = 1; j <= qind; j++){
    		val[i][j] = query(rarr[j].x1, rarr[j].y1, rarr[j].x2, rarr[j].y2);
    	}
    	for(auto x : gar[i]){
    		update(x.first.first, x.first.second, -x.second);
    	}
    }
    for(int i = 1; i <= q; i++){
    	if(narr[i].t){
    		ll ans = 0;
    		for(int j = 1; j <= k; j++){
    			if(swt[j])ans += val[j][narr[i].qind];
    		}
    		cout<<ans<<endl;
    	}else{
    		swt[narr[i].i] ^= true;
    	}
    }
}