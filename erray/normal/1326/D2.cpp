#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 1000000007
#define N 5000005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int t, bef[N];
string s;
string KMP(string s){
	string r = s;
	reverse(all(r));
	r = s + '*' + r;
	int now = 0, bef2 = -1;
	bef[0] = -1;
	while(now < r.size()){
		if(bef2 == -1 || r[now] == r[bef2]) bef[++now] = ++bef2;
		else bef2 = bef[bef2];	
	}
	string r2 = r.substr(0, bef[r.size()]);
	return r2;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
    	cin >> s;
    	int pos = 0;
    	while(s[pos] == s[s.size() - pos - 1] && s.size() - 1 - pos > pos ){
    		pos++;
    	}
    	if(pos == s.size() / 2){
    		cout << s << ln;
    		continue;
    	}
    	string se = s.substr(pos, s.size() - (pos * 2)), se2 = se;
    	reverse(all(se2));
    	//cout << " kalan " << se << ln;
    	string l1 = KMP(se), l2 = KMP(se2);
    	if(l2.size() > l1.size())l1 = l2;
    	cout << s.substr(0, pos) << l1 << s.substr(s.size() - pos) << ln;
    }
}