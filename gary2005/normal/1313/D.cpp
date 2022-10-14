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
vector<int> cover[200000+2];
mp seg[100000+2];
int n,m,val[200000+2],start[200000+2],k;
int dp[200000+2][1<<8];
map<int,pair<vector<int>,vector<int> > > M;
int main(){
	fastio;
	vector<int> vv;
	cin>>n>>m>>k;
	rb(i,1,n)
		cin>>seg[i].FIR>>seg[i].SEC,M[seg[i].FIR].FIR.PB(i),M[seg[i].SEC+1].SEC.PB(i);
	int las=0;
	int t=0;
	vector<int> now;
	vector<int> v1,v2;
	for(map<int,pair<vector<int>,vector<int> > > :: IT ite=M.begin();ite!=M.end();ite++){
		int pres=ite->FIR;
		v1=ite->SEC.FIR,v2=ite->SEC.SEC;
		for(auto it:v1){
			now.PB(it);
		}
		for(auto it:v2){
			now.erase(find(ALL(now),it));
		}
		t++;
		cover[t]=now;
		start[t]=pres;
		val[t-1]=pres-las;
		las=pres;
	}
//	cout<<"________________\n";
//	rb(i,1,t){
//		cout<<start[i]<<" "<<val[i]<<endl;
//		cout<<"{"<<endl;
//		for(auto it:cover[i]){
//			cout<<it<<" ";
//		}
//		cout<<"}"<<endl;
//	}
	int bc[1<<8]={0};
	rep(i,1<<8){
		int tmp=i;
		while(tmp){
			bc[i]+=tmp&1;
			tmp>>=1;
		}
	}
//	cout<<t<<endl;
	int res=0;
	rb(i,1,t-1){
		rep(mask,1<<cover[i].size()){
			int pmask=0,pnmask=0;
			rep(j,cover[i].size()){
				if(seg[cover[i][j]].FIR!=start[i]){
					// 
					if(mask&(1<<j))
					{
						pmask|=1<<(find(ALL(cover[i-1]),cover[i][j])-cover[i-1].begin());
					}
					else
					pnmask|=1<<(find(ALL(cover[i-1]),cover[i][j])-cover[i-1].begin());
				}	
				
			}
			pnmask=((1<<cover[i-1].size())-1)^pnmask;
			pnmask^=pmask;
			for(int bmask=pnmask;;bmask=pnmask&(bmask-1)){
				dp[i][mask]=max(dp[i][mask],dp[i-1][bmask|pmask]+val[i]*(bc[mask]&1));
				if(!bmask) break;
			}
			if(i==t-1){
				res=max(res,dp[i][mask]);
			}
		}
		
	} 
//	cout<<"!"<<dp[1][1]<<endl; 
	cout<<res<<endl;
	return 0;
}