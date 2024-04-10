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
#define N 200005
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
string s;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    vector <int> bas, son; 
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == ')'){
    		son.pb(i);
    	}
    	else bas.pb(i);
    }
    reverse(all(son));
    vector <vector <int> > ans; 
    while(1){
    	vector <int> start, end; 
    	for(int i = 0; i < min(bas.size(), son.size()); i++){
    		if(bas[i] < son[i]){
    			start.pb(bas[i]);
    			end.pb(son[i]);
    			bas.erase(bas.begin() + i);
    			son.erase(son.begin() + i);
    			i--;
    		}
    		else break;
    		if(bas.empty() || son.empty()){
    			break;
    		}
    	}
    	if(start.empty()){
    		break;
    	}
    	vector <int> don; 
    	reverse(all(end));
    	for(int i = 0; i < start.size(); i++){
    		don.pb(start[i]);
    	}
    	for(int i = 0; i < start.size(); i++){
    		don.pb(end[i]);
    	}
    	ans.pb(don);
    }
    cout << ans.size() << ln;
    for(auto a : ans){
    	cout << a.size() << ln;
    	for(auto a2 : a){
    		cout << a2 + 1 << " ";
    	}
    	cout << ln;
    }
	return 0;

}