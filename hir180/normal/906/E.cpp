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

const int maxn = 1000005, alpha = 26;
int len[maxn], link[maxn], to[maxn][alpha];
int slink[maxn], diff[maxn], series_ans[maxn];
int sz, last, n;
char ch[maxn];

//0...0
//1...-1
//len... 
//link... suffix link1
//to... 
//diff...len[x]-len[link[x]]
//slink... diff (diffO(log N))
//series_ans... diffDPmin (O(1)O(log N))

void init(){
	ch[n++] = -1;
	link[0] = 1;
	len[1] = -1;
	sz = 2;
}
//len[1] = -1-1
//
int get_link(int v){
	while(ch[n-len[v]-2] != ch[n-1]) v = link[v];
	return v;
}
//
void add_letter(char c){
	ch[n++] = c -= 'a';
	//
	last = get_link(last);
	
	//
	if(!to[last][c]){
		//
		len[sz] = len[last] + 2;
		link[sz] = to[get_link(link[last])][c];
		diff[sz] = len[sz] - len[link[sz]];
		
		//slink1
		//
		if(diff[sz] == diff[link[sz]]){
			slink[sz] = slink[link[sz]];
		}
		else{
			slink[sz] = link[sz];
		}
		//
		to[last][c] = sz++;
	}
	last = to[last][c];
}
string a,b,s;
int dp[1000005];
int pre[1000005];
int series_pre[1000005];

int main(){
	cin >> a >> b;
	s.resize(a.size()+b.size());
	rep(i,s.size()){
	    if(i%2 == 0) s[i] = a[i/2];
	    else s[i] = b[i/2];
	}
	init();
	rep(i,1000005) dp[i] = INF;
	rep(i,1000005) series_ans[i] = INF;
	dp[0] = 0;
	rep(i,s.size()){
		add_letter(s[i]);
		
		if(i%2 == 1 && s[i] == s[i-1] && dp[i+1] > dp[i-1]){
			dp[i+1] = dp[i-1];
			pre[i+1] = i-1;
		}
		for(int v=last; len[v] > 0 ; v = slink[v]){
			series_ans[v] = dp[i+1-len[slink[v]]-diff[v]];
			series_pre[v] = i+1-len[slink[v]]-diff[v];
			
			if(diff[v] == diff[link[v]]){
				if(series_ans[v] > series_ans[link[v]]){
					series_pre[v] = series_pre[link[v]];
					series_ans[v] = series_ans[link[v]];
				}
			}
			if(i%2 == 1 && dp[i+1] > series_ans[v]+1){
				dp[i+1] = series_ans[v] + 1;
				pre[i+1] = series_pre[v];
			}
		}
	}
	if(dp[s.size()] > 5e8){
	    puts("-1");
	    return 0;
	}
	cout << dp[s.size()] << endl;
	int cur = s.size();
	vector<P>vec;
	while(cur){
		int x = pre[cur];
		if(x+2 < cur){
			printf("%d %d\n", x/2+1, cur/2);
		}
		cur = x;
	}
}