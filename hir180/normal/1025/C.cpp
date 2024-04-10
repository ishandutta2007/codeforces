#include <bits/stdc++.h>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
string str;
int n;
int main(){
	cin>>str;
	n = str.size();
	str = str+str;
	int cur = 0,ans = 0;
	for(int i=1;i<str.size();i++){
		if(str[i-1] == str[i]){
			ans = max(ans,cur+1);
			cur = 0;
		}
		else{
			cur++;
		}
	}
	ans = max(ans,cur+1);
	ans = min(ans,n);
	cout<<ans<<endl;
}