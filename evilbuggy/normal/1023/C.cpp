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

	int n, k;
	string s;
	cin>>n>>k>>s;
	stack<int> st;
	int pr[n];
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			st.push(i);
		}else{
			int j = st.top();
			st.pop();
			pr[i] = j;
			pr[j] = i;
		}
	}
	int vis[n] = {0};
	for(int i = 0; i < n; i++){
		if(vis[i])continue;
		vis[i] = 1;
		vis[pr[i]] = 1;
		k -= 2;
		if(!k)break;
	}
	for(int i = 0; i < n; i++){
		if(vis[i])cout<<s[i];
	}
	cout<<endl;

	return 0;
}