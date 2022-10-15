#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first 
#define nd second 
#define ln "\n"
#define MAX 1000000009
#define MOD 1000000007
#define N 5005
using namespace std;	
typedef long long ll;	
typedef pair<int ,int > pii;
int t, n, x, ct[N], pref[N];
vector <int> divi[N];
vector <int>  primes;  
ll ans = 0;
int main(){	
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	for(int i = 2; i < N; i++){
		bool flag = 1;
		for(int j = 0; j < primes.size() && j <= sqrt(i); j++){
		    auto a = primes[j];
			if(i % a == 0){
				flag = 0;
				break;
			}
		}
		if(flag)primes.pb(i);
	}
//	for(auto a : primes)cout << a << " ";
	
	for(int i = 2; i < N; i++){
		int num = i;
		for(int j = 2; j <= num; j++){
			while(num % j == 0){
				num /= j;
				divi[i].pb(j);
			}
		}
	}
	cin >> t;
	int tt = t;
	vector <int> xx; 
	while(t--){
		cin >> n;
		//xx.pb(n);
		ct[max(1, n)]++;
	}
	
	//sort(all(xx));
	//for(auto a : xx) cout << a << " ";
	t = tt;
	int point = -1;
	primes.pb(5001);
	for(int i = 0; i < primes.size() - 1; i++){
		int tmp = 0;
		for(int j = primes[i]; j < primes[i + 1]; j++){
			tmp += ct[j];
		}
		if(tmp > t / 2){
			point = i;
			break;
		}
	}
	for(int i = 2; i <= 5000; i++){
		for(int j = 2; j <= i; j++ ){
			ans += ct[i] * divi[j].size();
		}
	}
	if(point != -1){
		int prime = primes[point];
		multiset<int> pq[N]; 
		vector <int> nums;   
		for(int i = prime; i < primes[point + 1]; i++){
			if(ct[i]){
				nums.pb(i);
				for(int q = 2; q <= i; q++){
					for(auto a : divi[q]){
						pq[i].insert(a);
					}
				}
			}
		}
		while(1){
			umap <int, int> sayi;
			set <int> S;   
			vector <int> best[N]; 
			for(auto a : nums){
				//cout << a << " "; 
				if(!pq[a].empty()){
					S.insert(*(--pq[a].end()));
					sayi[*(--pq[a].end())] += ct[a];
					best[(*--pq[a].end())].pb(a);
					//cout << *(--pq[a].end()) << " " << a << ln;	
					pq[a].erase(--pq[a].end());
				}
			}
			if(S.empty())break;
			bool cont = 0;
			for(auto a : S){
				if(sayi[a] > t / 2){
					//cout << a << " " << sayi[a] << ln;
					ans -= sayi[a];
					ans += t - sayi[a];
					cont = 1;
					nums = best[a];
					break;
				}
			}	
			if(!cont){
				cout << ans;
				return 0;
			}
		}
	}
	cout << ans << ln;
	return 0;	 
}