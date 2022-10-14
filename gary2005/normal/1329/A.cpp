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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int l[100000+20];
int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	LL sum=0;
	rb(i,1,m)
		cin>>l[i],sum+=l[i];
	if(sum<(LL)(n)){
		cout<<-1<<endl;
	}
	else{
		rb(i,1,m){
			if(l[i]+i-1>n){
				cout<<-1<<endl;
				return 0;
			}
		}
		vector<mp> seg;
		rb(i,1,m){
			seg.PB(II(i,i+l[i]-1));
		}
		int maxi[100000+20];
		memset(maxi,-63,sizeof(maxi));
		rl(i,m-1,0){
			maxi[i]=max(maxi[i+1],seg[i].SEC);
		} 
		int move=0;
		rb(i,0,m-1){
			if(maxi[i]+move==n){ 
				rb(j,i,m-1){
					cout<<seg[j].FIR+move<<" ";
				}
				return 0;
			}
			else{
				cout<<move+seg[i].FIR<<" ";
				int MM=min(n-(maxi[i+1]+move),l[i+1]-1);
				move+=MM;
			}
		}
	}
	return 0;
}