#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 1000000007;
map<string,int>A;
map<string,int>B;
bool cmp(const string &a,const string &b){
	return a.size() < b.size();
}
int main(){
	int n; cin >> n;
	if(n <= 3){
		string ans = "";
		repn(i,n){
			cout << "? " << i << " " << i << endl;
			string s; cin >> s;
			ans += s;
		}
		cout << "! " << ans << endl;
		return 0;
	}
	int x = 2 * n / 3;
	cout << "? " << 2 << " " << x << endl;
	rep(i,(x-1)*x/2){
		string s; cin >> s;
		SORT(s); A[s]++;
	}
	
	cout << "? " << 1 << " " << x << endl;
	rep(i,(x+1)*x/2){
		string s; cin >> s;
		SORT(s); B[s]++;
	}
	vector<string>vec;
	for(auto x:B){
		if(x.sc > A[x.fi]){
			assert(x.sc == A[x.fi]+1);
			vec.pb(x.fi);
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int pre[26]={};
	string ret = "";
	rep(i,vec.size()){
		int nxt[26]={};
		rep(j,vec[i].size()) nxt[vec[i][j]-'a']++;
		rep(i,26){
			if(nxt[i] > pre[i]){
				assert(nxt[i] == pre[i]+1);
				ret.pb('a'+i);
				break;
			}
		}
		rep(i,26) pre[i] = nxt[i];
	}
	
	int zan = n-x;
	cout << "? " << n-2*zan+1 << " " << n << endl;
	map<string,int>len[105];
	rep(i,(2*zan+1)*2*zan/2){
		string s; cin >> s;
		SORT(s); len[s.size()][s]++;
	}
	int numm[26]={};
	string all;
	for(auto a:len[2*zan]){
	    all = a.fi;
		rep(j,(a.fi).size()) numm[(a.fi)[j]-'a']++;
	}
	rep(i,zan) ret.pb('1');
	for(int i=2*zan-1;i>=zan;i--){
		map<string,int>M;
		for(int j=n+1-2*zan;j+i-1<n;j++){
			//[j,j+i-1]
			string S = all;
			for(int x=n-2*zan;x<j;x++) {
			    rep(i,S.size()){
			        if(S[i] == ret[x]){
			            swap(S[i],S[S.size()-1]);
			            S.pop_back();
			            break;
			        }
			    }
			}
			for(int x=j+i;x<n;x++){
			    rep(i,S.size()){
			        if(S[i] == ret[x]){
			            swap(S[i],S[S.size()-1]);
			            S.pop_back();
			            break;
			        }
			    }
			}
			SORT(S);
			M[S]++;
		}
		for(auto a:len[i]){
			if(a.sc != M[a.fi]){
				string ss = a.fi;
				for(int x=n-2*zan+1+i;x<n;x++) ss.pb(ret[x]);
				int nn[26]={};
				rep(i,ss.size()) nn[ss[i]-'a']++;
			
    			rep(ii,26){
    				if(nn[ii] < numm[ii]){
    					ret[n-2*zan+i] = 'a'+ii;
    				}
    			}
			}
		}
	}
	cout << "! " << ret << endl;
}