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
#define INF 10000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())

string s[2];
int n,q;
set<P2>used;
int main(){
	cin >> q;
	while(q--){
		cin >> n;
		cin >> s[0] >> s[1];
		int cx = 0, cy = 0;
		int dx[4]={0,1,0,-1};
		int dy[4]={1,0,-1,0};
		int dir = 0;
		bool ok = 0;
		int loop = 0;
		while(1){
			loop ++; if(loop > 3*n) break;
			//cout << cx << " " << cy << endl;
			if(s[cx][cy]-'0' <= 2){
				rep(k,4){
					if(dir != k) continue;
					int nx = cx + dx[k];
					int ny = cy + dy[k];
					if(nx == 1 && ny == n){
						ok = 1; break;
					}
					else if(nx < 0 || nx > 1) continue;
					else if(ny < 0 || ny >= n) continue;
					else{
						cx = nx; cy = ny;
						dir = k;
						goto nxt;
					}
				}
				break;
			}
			else{
				rep(k,4){
					if(dir%2 == k%2) continue;
					if(k == 2) continue;
					int nx = cx + dx[k];
					int ny = cy + dy[k];
					if(nx == 1 && ny == n){
						ok = 1; break;
					}
					else if(nx < 0 || nx > 1) continue;
					else if(ny < 0 || ny >= n) continue;
					else{
						cx = nx; cy = ny;
						dir = k;
						goto nxt;
					}
				}
				break;
			}
			nxt:;
		}
		puts(ok?"YES":"NO");
	}
}