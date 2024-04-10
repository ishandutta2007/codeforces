#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n, a, b, c;
		cin>>n>>a>>b>>c;
		string str;
		cin>>str;
		vector<int> r, p, s;
		for(int i = 0; i < n; i++){
			if(str[i] == 'R')r.push_back(i);
			if(str[i] == 'P')p.push_back(i);
			if(str[i] == 'S')s.push_back(i);
		}
		int score = 0;
		score += min(a, (int) s.size());
		score += min(b, (int)r.size());
		score += min(c, (int)p.size());
		if(2*score >= n){
			cout<<"YES"<<endl;
			vector<char> ans(n);
			while(a > 0 && !s.empty()){
				ans[s.back()] = 'R';
				s.pop_back();
				a--;
			}
			while(b > 0 && !r.empty()){
				ans[r.back()] = 'P';
				r.pop_back();
				b--;
			}
			while(c > 0 && !p.empty()){
				ans[p.back()] = 'S';
				p.pop_back();
				c--;
			}
			while(!s.empty()){
				if(c > 0){
					ans[s.back()] = 'S';
					c--;
				}else{
					ans[s.back()] = 'P';
					b--;
				}
				s.pop_back();
			}
			while(!r.empty()){
				if(a > 0){
					ans[r.back()] = 'R';
					a--;
				}else{
					ans[r.back()] = 'S';
					c--;
				}
				r.pop_back();
			}
			while(!p.empty()){
				if(b > 0){
					ans[p.back()] = 'P';
					b--;
				}else{
					ans[p.back()] = 'R';
					a--;
				}
				p.pop_back();
			}
			for(auto ch : ans){
				cout<<ch;
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}