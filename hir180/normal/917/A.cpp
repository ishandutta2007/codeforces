#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,pair<double,double> > P2;
typedef pair<pair<double,double>,P> P3;
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
int ruii[5005],rui2[5005];
int rui[5005][3];
int ok[5005][5005];
int main(){
	cin>>s;
	rep(i,s.size()){
		if(s[i] == ')') ruii[i+1] = ruii[i]-1;
		else ruii[i+1] = ruii[i]+1;
		rep(j,3) rui[i+1][j] = rui[i][j];
		if(s[i] == '(') rui[i+1][0]++;
		else if(s[i] == ')') rui[i+1][1]++;
		else rui[i+1][2]++;
	}
	for(int i=s.size()-1;i>=0;i--){
		if(s[i] == '(') rui2[i] = rui2[i+1]+1;
		else rui2[i] = rui2[i+1]-1;
	}
	int ans = 0;
	for(int l=0;l<s.size();l++){
		int x = ruii[l];
		for(int r=l;r<s.size();r++){
		    if(ruii[r+1] < x) break;
			if((r-l+1)%2 == 1) continue;
			int x = rui[r+1][0]-rui[l][0];
			int y = rui[r+1][1]-rui[l][1];
			int z = rui[r+1][2]-rui[l][2];
			if(x > y+z || y > x+z) continue;
			int a = (x+y+z)/2-x;
			int b = (x+y+z)/2-y;
			ok[l][r]++;
		}
	}
	for(int r=0;r<s.size();r++){
		int x = rui2[r+1];
		for(int l=r;l>=0;l--){
		    if(rui2[l] > x) break;
			if((r-l+1)%2 == 1) continue;
			int x = rui[r+1][0]-rui[l][0];
			int y = rui[r+1][1]-rui[l][1];
			int z = rui[r+1][2]-rui[l][2];
			if(x > y+z || y > x+z) continue;
			int a = (x+y+z)/2-x;
			int b = (x+y+z)/2-y;
			ok[l][r]++;
		}
	}
	rep(i,5005)rep(j,5005) {ans+=(ok[i][j]==2);}
	cout<<ans<<endl;
}