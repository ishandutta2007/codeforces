#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define umap unordered_map
#define flush fflush(stdout)
#define For(ii,aa,bb) for(int ii = aa; ii < bb; ii++) 
#define st first
#define nd second 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ln "\n"
#define all(v) v.begin(),v.end()
#define MAX 1000000009
#define MOD 1000000007
#define mid (start + end) / 2 
#define R(ii) (ii + ii + 1)
#define L(ii) (ii + ii)
#define N 100005
using namespace std;
typedef pair<ll,ll> pp;
typedef vector<ll> vi; 
ll n, t, x, a, b, c;
string s;
/*
void BFS(ll now, ll yon, ll times){
	for(int i = 1; i <= times;i++){ 
		s[now + i * yon] = s[now];
	}
}
*/
pp uz(ll now){
	ll start = now, end = now;
	while(s[start % t] != s[(start + 1) % t]){
		start++;
	}
	while(s[(end + t ) % t] != s[(end - 1 + t) % t]){
		//cout << end << " " << ((end - 1 + t) % t) << ln;
		end--;
	}
	return mp(end, start);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t >> n >> s;
    t = s.size();
    if(t % 2 == 0){
    	bool f = 1;
    	for(int i = 0; i < t - 1; i++){
    		if(s[i] == s[i + 1]){
    			f = 0;
    		}
    	}
    	if(f){
    		if(n % 2 == 1){
    			string tmp  = s;
    			s.erase(s.begin());
    			s+= *tmp.begin();
    		}
    		cout << s;
    		return 0;
    	}

    }
    /*
	--n;
	string tmp = s;
	for(int i = 0; i < t; i++){
		
		if(tmp[(i - 1 + t) % t] == tmp[(i + 1) % t]){ 
			s[i] = tmp[(i + 1) % t];}
	}
	*/
	vector <pp> v; 
    if (n > 0){
    
    	ll sinir = t;
    	for(int i = 0; i < min(t, sinir); i++){
    		pp p = uz(i);
    		ll start = p.st, end = p.nd;
    		//cout << start << " " << end << ln;
     		if(start < 0){
    			sinir = start + t;
    		}
    		if(end - start > 1){
    			v.pb(mp(start, end));
    		}
    		i = end;
    	}
    }
    for(auto a : v){
    	ll start = a.st, end = a.nd;
    	for(int i = 1 ; i <= (end - start) / 2; i++){
    		if(i <= n){
    			s[(start + i + t) % t] = s[(start + t) % t];
    			s[(end - i + t) % t] = s[end % t];
    		}
    		else{
    			s[(start + i + t) % t] = (s[(start + i + t - 1) % t] == 'B' ? 'W' : 'B');
    			s[(end - i + t) % t] = (s[(end - i + t + 1) % t]  == 'B' ? 'W' : 'B');
    		}
    		
    	}
    }

    
    cout << s;
    return 0;
	
}