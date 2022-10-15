#include<bits/stdc++.h>          

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	vector<int> ans;
	if(v[v.size() - 1] != 0)return cout << -1, 0;
	int m1, m2, m3;
	m1 = m2 = m3 = -1;
	int rem = accumulate(v.begin(), v.end(), 0)%3;
	for(int a : v){
		if(a%3 == rem)m1 = a;
		else if((a<<1)%3 == rem){
			m3 = m2;
			m2 = a;
		}
	}
	if(!rem)ans = v;
	else {
		if(m1 == -1 && m3 == -1)return cout << -1, 0;
		if(m1 != -1)m2 = m3 = -1;
		for(int a : v){
			if(a == m1)m1 = -1;
			else if(a == m2)m2 = -1;
			else if(a == m3)m3 = -1;
			else ans.push_back(a);
		}	
	}
	if(ans.empty())cout << -1;
	else{
		if(accumulate(ans.begin(), ans.end(), 0) == 0)cout << 0;
		else for(int a : ans)cout << a;
	}
}