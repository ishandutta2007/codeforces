#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int main(){
	string s; cin>>s;
	string t;
	int cut = -1;
	for(int i=0;i<s.size();i++){
		bool bad = 0; t.pb(s[i]);
		set<int>S;
		for(int j=i;j>=cut+1;j--){
			if(s[j]=='a'||s[j]=='i'||s[j]=='u'||s[j]=='e'||s[j]=='o'){
				break;
			}
			else{
				S.insert(s[j]);
				if(S.size() >= 2 && i-j+1>=3){
					cut = i-1; t.pb(' '); swap(t[t.size()-1],t[t.size()-2]); break;
				}
			}
		}
	}
	cout<<t<<endl;
}