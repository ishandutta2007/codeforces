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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n,m;
bool rev;
int go[100005];
//shitty problem...
int main(){
	cin >> n >> m;
	if(n > m){
		int id = 1;
		rep(j,m){
			rep(i,n){
				go[id++] = 1+i*m+j;
			}
		}
		swap(n,m) ;
		rev = 1;
	}
	
	if(n == 1){
	    if(m == 1){
	        puts("YES");
	        puts("1");
	    }
		else if(m <= 3){
			puts("NO");
		}
		else{
			puts("YES");
			if(!rev){
				for(int i=m;i>=1;i--){
					if(i%2 == 0) continue;
					printf("%d ",i);
				}
				for(int i=m;i>=1;i--){
					if(i%2 == 1) continue;
					printf("%d ",i);
				}
				puts("");
			}
			else{
				for(int i=m;i>=1;i--){
					if(i%2 == 0) continue;
					printf("%d\n",i);
				}
				for(int i=m;i>=1;i--){
					if(i%2 == 1) continue;
					printf("%d\n",i);
				}
			}
		}
		return 0;
	}
	else if(n == 2){
		if(m <= 3){
			puts("NO");
		}
		else if(m == 4){
			puts("YES");
			if(!rev){
				puts("3 1 4 2");
				puts("6 8 5 7");
			}
			else{
				puts("5 4");
				puts("1 8");
				puts("7 2");
				puts("3 6");
			}
		}
		else {
			puts("YES");
			vector<vector<int>>vec;
			{
				int beg = 0;
				rep(j,n){
					vector<int>hoge;
					if(j%2 == 1){
						for(int i=m;i>=1;i--){
							if(i%2 == 0) continue;
							hoge.pb(beg+i);
						}
						for(int i=m;i>=1;i--){
							if(i%2 == 1) continue;
							hoge.pb(beg+i);
						}
					}
					else{
						for(int i=m;i>=1;i--){
							if(i%2 == 1) continue;
							hoge.pb(beg+i);
						}
						for(int i=m;i>=1;i--){
							if(i%2 == 0) continue;
							hoge.pb(beg+i);
						}
					}
					beg+=m;
					vec.pb(hoge);
				}
			}
			if(!rev){
				rep(i,vec.size()){
					rep(j,vec[0].size()) printf("%d ",vec[i][j]);
					puts("");
				}
			}
			else{
				rep(j,vec[0].size()){
					rep(i,vec.size()) printf("%d ",go[vec[i][j]]);
					puts("");
				}
			}
		}
		return 0;
	}
	else if(n == 3){
		if(m == 3){
			puts("YES");
			puts("1 3 4");
			puts("5 7 6");
			puts("9 2 8");
			return 0;
		}
		else if(m == 4){
			if(!rev){
				puts("YES");
				puts("3 1 4 2");
				puts("6 8 5 7");
				puts("11 9 12 10");
			}
			else{
				puts("YES");
				puts("7 5 9");
				puts("1 11 3");
				puts("10 2 12");
				puts("4 8 6");
			}
			return 0;
		}
	}
	else if(n == 4 && m == 4){
		puts("YES");
		puts("3 1 4 2");
		puts("6 8 5 7");
		puts("11 9 12 10");
		puts("14 16 13 15");
		return 0;
	}
	//m >= 5
	puts("YES");
	vector<vector<int>>vec;
			{
				int beg = 0;
				rep(j,n){
					vector<int>hoge;
					if(j%2 == 1){
						for(int i=m;i>=1;i--){
							if(i%2 == 0) continue;
							hoge.pb(beg+i);
						}
						for(int i=m;i>=1;i--){
							if(i%2 == 1) continue;
							hoge.pb(beg+i);
						}
					}
					else{
						for(int i=m;i>=1;i--){
							if(i%2 == 1) continue;
							hoge.pb(beg+i);
						}
						for(int i=m;i>=1;i--){
							if(i%2 == 0) continue;
							hoge.pb(beg+i);
						}
					}
					beg+=m;
					vec.pb(hoge);
				}
			}
	
	if(!rev){
				rep(i,vec.size()){
					rep(j,vec[0].size()) printf("%d ",vec[i][j]);
					puts("");
				}
			}
			else{
				rep(j,vec[0].size()){
					rep(i,vec.size()) printf("%d ",go[vec[i][j]]);
					puts("");
				}
			}
			}