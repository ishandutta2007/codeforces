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
int a[105],b[105],n,m;
set<int>s[105][2],all;
int main(){
	cin>>n>>m;
	rep(i,n) cin>>a[i*2]>>a[i*2+1];
	rep(i,m) cin>>b[i*2]>>b[i*2+1];
	rep(i,n){
		rep(j,m){
			map<int,int>M;
			M[a[i*2]]++;
			M[a[i*2+1]]++;
			M[b[j*2]]++;
			M[b[j*2+1]]++;
			if(M.size() != 3) continue;
			for(map<int,int>::iterator it=M.begin();it!=M.end();++it){
				if(it->sc == 2){
					int c = it->fi;
					s[i][0].insert(c);
					s[j][1].insert(c);
					all.insert(c);
				}
			}
		}
	}
	if(all.size() == 1){
		cout<<*all.begin()<<endl;
	}
	else{
		rep(i,n) if(s[i][0].size() >= 2){
			puts("-1"); return 0;
		}
		rep(j,m) if(s[j][1].size() >= 2){
			puts("-1"); return 0;
		}
		puts("0");
	}
}