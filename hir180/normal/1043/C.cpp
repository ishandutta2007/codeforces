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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
string str;
vector<int>ans;
int main(){
	cin>>str;
	bool rev = 0;
	for(int i=str.size()-1;i>=0;i--){
		if(!rev){
			if(str[i] == 'b'){
				ans.pb(0);
			}
			else{
				rev = 1;
				ans.pb(1);
			}
		}
		else{
			if(str[i] == 'a'){
				ans.pb(0);
			}
			else{
				rev = 0;
				ans.pb(1);
			}
		}
	}
	for(int i=str.size()-1;i>=0;i--){
		printf("%d ",ans[i]);
	}
	puts("");
}