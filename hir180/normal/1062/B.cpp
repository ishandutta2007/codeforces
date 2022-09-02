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
int x;
int y=1;
vector<int>vec;
int main(){
	cin>>x;
	if(x == 1){
	    cout<<1<<" "<<0<<endl; return 0;
	}
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			y *= i;
			int C = 0;
			while(x%i==0){
				C++;
				x/=i;
			}
			vec.pb(C);
		}
	}
	if(x > 1){
		vec.pb(1);
		y *= x;
	}
	for(int i=0;;i++){
	    int add = 0;
		for(int j=0;j<vec.size();j++){
			if((1<<i) < vec[j]) goto nxt;
		}
		//sqrt: i time
		
		for(int j=0;j<vec.size();j++){
			if((1<<i) > vec[j]) add=1;
		}
		cout<<y<<" "<<i+add<<endl;
		return 0;nxt:;
	}
}