/*
{By GWj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int a[101];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		R(n);
		rb(i,1,n)
			R(a[i]);
		priority_queue<int> q;
		rb(i,1,n){
			q.push(a[i]);
		}
		int is=0;
		mp las=II(-1,-1);
		while(1){
			if(las.FIR>0)
				q.push(las.FIR);
			swap(las.FIR,las.SEC);
			if(q.empty()){
				break;
			}
			las.SEC=q.top();
			q.pop();
			las.SEC--;
			is^=1;
		}
		cout<<(is? "T":"HL")<<endl;
	}
	return 0;
}