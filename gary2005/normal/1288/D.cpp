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
int n,m,store[512]={1},maxi[512]={INF},tmp[512]={INF},a[300000+1][9];
bool check(int x){
	rb(i,1,n){
		int mask=0;
		rb(j,1,m)
		{
			if(a[i][j]<x){
				mask+=(1<<(j-1));
			}
		}
//		cout<<maxi[mask]<<endl;
		if(maxi[mask]>=x) return 1;
	}
	return 0;
}
void recover(int x){
	rb(i,1,n){
		int mask=0;
		rb(j,1,m)
		{
			if(a[i][j]<x){
				mask+=(1<<(j-1));
			}
		}
		if(maxi[mask]>=x){
			cout<<i<<" "<<store[mask]<<endl;
			return ;
		}
	}
}
int main(){
	fastio;
	cin>>n>>m;
	rb(i,1,n)
		rb(j,1,m)
			{
				cin>>a[i][j];
			}
	rb(i,1,n){
		rb(j,1,(1<<m)-1){
			int las=(j)&(j-1),tmp_=j ^ las;
//			cout<<tmp_<<"*"<<endl;
			tmp_=(int)(log2((double)tmp_))+1;
//			cout<<tmp_<<endl;
			tmp[j]=min(a[i][tmp_],tmp[las]);
//			cout<<i<<" "<<j<<" "<<tmp[j]<<endl;
		}
		rb(j,1,(1<<m)-1){
			if(maxi[j]<=tmp[j]){
				maxi[j]=tmp[j];
				store[j]=i;
			}
		}
	}
	int l=0,r=1e9+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid;
		else r=mid;
	}
//	cout<<l<<endl;
//	cout<<check(3)<<endl;
	recover(l);
	return 0;
}