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
int n;
int cnt[1005];
int ans[25][25];
int main(){
	cin>>n;
	rep(i,n*n){int a;cin>>a;cnt[a]++;}
	rep(ii,n)rep(j,n){
		if(ans[ii][j]) continue;
		int use = 1;
		if(ii != n-1-ii) use*=2;
		if(j != n-1-j) use*=2;
		
		for(int i=1;i<=1000;i++){
			if(cnt[i] >= use && !(use==1&&cnt[i]%2==0) && !(use==2&&cnt[i]%4==0)){
				vector<int>vx,vy;
				vx.pb(ii);
				if(ii != n-1-ii) vx.pb(n-1-ii);
				vy.pb(j);
				if(j != n-1-j) vy.pb(n-1-j);
				rep(ii,vx.size())rep(jj,vy.size()){
					ans[vx[ii]][vy[jj]] = i;
					cnt[i]--;
				}
				goto nxt;
			}
		}
		for(int i=1;i<=1000;i++){
			if(cnt[i] >= use && !(use==1&&cnt[i]%2==0)){
				vector<int>vx,vy;
				vx.pb(ii);
				if(ii != n-1-ii) vx.pb(n-1-ii);
				vy.pb(j);
				if(j != n-1-j) vy.pb(n-1-j);
				rep(ii,vx.size())rep(jj,vy.size()){
					ans[vx[ii]][vy[jj]] = i;
					cnt[i]--;
				}
				break;
			}
		}
		nxt:;
	}
	rep(i,n)rep(j,n){
		if(!ans[i][j]){puts("NO"); return 0;}
	}
	puts("YES");
	rep(i,n){rep(j,n)cout<<ans[i][j]<<" "; cout<<endl;}

}