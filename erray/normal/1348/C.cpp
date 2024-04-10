#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair  
#define st first 
#define nd second 
#define all(v)  v.begin(),v.end()
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		string s;
		cin >> n >> k >> s;
		sort(all(s));
		set <int> ch[n/k + 5];	
		ll sum = 0;
		for(int i = 0; i < n; ++i){
			ch[i/k].insert(s[i]);
		}
		if(ch[0].size() == 1){
			set <int> ct;
			cout << (char)*(ch[0].begin());
			for(int i = k; i < n; ++i){
				ct.insert(s[i]);
			} 	
			if(ct.size() <= 1){
				for(int i = 0; i < (int)ceil((double)n/k) - 1; ++i)cout << s[s.size() - 1];	
			}                	
			else {
				for(int i = k; i < n; ++i)cout << s[i];
			}
		}
		else {
			cout << (char)*(--ch[0].end());
		}
		cout << ln; 
	}	
}