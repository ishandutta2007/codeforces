/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5;
const int MAGIC=500;
int n;
LL sum[MAGIC+1][5];
int siz[MAGIC+1];
bool is[MAGIC*MAGIC+20];
int real_[100000+30];
void recompute(int x,int l,int r){
	siz[x]=0;
	rep(i,5)
		sum[x][i]=0;
	rb(i,l,r)
	{
		 if(is[i]){
		 	siz[x]++;
		 	sum[x][siz[x]%5]+=real_[i];
		 }
	} 
}
string sq[100000+20];
int nq[100000+20];
map<int,int> M;
int main(){
	fastio;
	R(n);
	rb(i,1,n){
		R(sq[i]);
		if(sq[i]!="sum"){
			R(nq[i]);
			M[nq[i]]=1;
		}
	}
	int cnt_=0; 
	for(map<int,int> :: IT ite=M.begin();ite!=M.end();ite++){
		ite->SEC=++cnt_;
		real_[cnt_]=ite->FIR;
	}
	rb(Q,1,n){
		string s=sq[Q];
		int x;
		if(s=="add"){
			x=M[nq[Q]];
			int x_=x/MAGIC;
			if(x%MAGIC!=0){
				x_++;
			}
			int l,r;
			l=(x_-1)*MAGIC+1;
			r=x_*MAGIC;
			is[x]=1;
			recompute(x_,l,r);
		}
		else{
			if(s=="del"){
			x=M[nq[Q]];
				int x_=x/MAGIC;
			if(x%MAGIC!=0){
				x_++;
			}
			int l,r;
			l=(x_-1)*MAGIC+1;
			r=x_*MAGIC;
			is[x]=0;
			recompute(x_,l,r);
			}
			else{
				int all=0;
				LL res=0;
				rb(i,1,MAGIC){// (all+j)%5=3
					all%=5;
					int j=3-all;
					j+=5;
					j%=5;
					all+=siz[i];
					res+=sum[i][j];
				}
				cout<<res<<endl;
			}
		}
	}
	return 0;
}