#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
string s;
int main(){
	cin>>s;
	if(s.size()%2 == 0){
		int n = s.size();
		for(int i=1;i<n;i++){
			string a="",b="";
			rep(x,i) a.pb(s[x]);
			rep(x,n-i) b.pb(s[i+x]);
			b += a;
			int j = 0;
			while(j < n-1-j){
				if(b[j] != b[n-1-j]) goto fail;
				j++;
			}
			if(s == b) continue;
			cout<<1<<endl; return 0; fail:;
		}
		rep(i,n-1){
			if(s[i] != s[i+1]){
				cout<<2<<endl; return 0;
			}
		}
		cout<<"Impossible"<<endl;
	}
	else{
		string a = "", b = "";
		int n = s.size();
		rep(i,n/2-1){
			if(s[i] != s[i+1]){
				cout<<2<<endl; return 0;
			}
		}
		cout<<"Impossible"<<endl;
	}
}