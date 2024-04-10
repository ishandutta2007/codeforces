    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
    typedef unsigned long long ull;
     
    int n, lo[7][7], hi[7][7], a[7][7];
    map<vector<int>, ll> mem[7][7];
     
    ll dp(int x, int y, vector<int> &flow){
    	if(x == n - 2 && y == n - 1){
    		if(lo[x][y] <= flow[x] && flow[x] <= hi[x][y])return flow[x]*flow[x] + ((flow[x] > 0)?a[x][y]:0);
    		return -1;
    	}
    	if(mem[x][y].count(flow))return mem[x][y][flow];
    	ll ret = -1;
    	for(int fl = lo[x][y]; fl <= hi[x][y]; fl++){
    		if(fl > flow[x])break;
    		flow[x] -= fl;
    		flow[y] += fl;
    		if(y == n - 1 && flow[x] == 0){
    			ll tmp = dp(x + 1, x + 2, flow);
    			if(tmp != -1){
    				tmp += fl*fl;
    				if(fl > 0)tmp += a[x][y];
    				ret = max(ret, tmp);
    			}
    		}else if(y < n - 1){
    			ll tmp = dp(x, y + 1, flow);
    			if(tmp != -1){
    				tmp += fl*fl;
    				if(fl > 0)tmp += a[x][y];
    				ret = max(ret, tmp);
    			}
    		}
    		flow[x] += fl;
    		flow[y] -= fl;
    	}
    	return mem[x][y][flow] = ret;
    }
     
    int main(){
    	ios::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout<<setprecision(32);
     
    	cin>>n;
    	int s, f, l, h, x;
    	for(int i = 0; i < n*(n - 1)/2; i++){
    		cin>>s>>f>>l>>h>>x;
    		lo[s - 1][f - 1] = l;
    		hi[s - 1][f - 1] = h;
    		a[s - 1][f - 1] = x;
    	}
    	for(int fl = 0; fl <= 25; fl++){
    		vector<int> flow(n, 0);
    		flow[0] = fl;
    		ll tmp = dp(0, 1, flow);
    		if(tmp != -1){
    			cout<<fl<<" "<<tmp;
    			exit(0);
    		}
    	}
    	cout<<"-1 -1";
     
    	return 0;
    }