/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,dontmove[200000+1];
int main(){
	fastio;
	cin>>n>>m;
	vector<vector<int>  > maze;
	vector<int> tmp;
	rb(i,1,m)
		tmp.PB(0);
	rb(i,1,n)
		maze.PB(tmp);
	rep(i,n)
		rep(j,m)
			cin>>maze[i][j];
	int res=0;
	rep(j,m)
		{
			int tmp=INF;
			rep(i,n)
				dontmove[i]=0;
			rep(i,n)
			{
				if((maze[i][j]-j-1)%m==0){
					int ned=(maze[i][j]-j-1)/m;
					if(ned>=n) continue;
//					cout<<i<<"_"<<j<<" "<<" "<<maze[i][j]<<" "<<ned<<endl;
					if(i<ned){
						dontmove[i+1+(n-1)-ned]++;
					}
					else{
//						cout<<ned+1+(n-1)-i<<"_---"<<i<<" "<<j<<endl; 
						dontmove[i-ned]++;
					}
				}	
			}
			rep(i,n){
//				cout<<j<<" "<<i<<" "<< dontmove[i]<<endl;
				tmp=min(tmp,n-dontmove[i]+i);
			}
			res+=tmp;
		}
	cout<<res;
	return 0;
}