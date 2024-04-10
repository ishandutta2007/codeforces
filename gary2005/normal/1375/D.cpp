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
int n,a[1001],used[2001],pointer=0;
int mex(){
	rb(i,0,n+n)
	{
		if(!used[i]) return i;
	}
	return 0;
}
bool ok[1001];
void solve(){
	R(n);
	pointer=0;
	rb(i,1,n)
		R(a[i]);
	rb(i,0,2*n)
		used[i]=0;
	rb(i,1,n)used[a[i]]++; 
	vector<int> rest;
	rb(i,1,n){
		if(a[i]==i-1) continue;
		rb(j,1,n){
			if(a[j]==i-1){
				int save=a[j];
				int m=mex();
				while(m<n){	
					int ssave=a[m+1];
					a[m+1]=m;
					rest.PB(m+1);
					used[ssave]--;
					used[m]++;
					m=mex();
				}
				if(a[j]!=j-1){
					rest.PB(j);
					save=a[j];
					a[j]=m;
					used[save]--;
					used[a[j]]++;
					
				}
			}
		}
		if(a[i]!=i-1){
		rest.PB(i);
		int save=a[i];
		a[i]=mex();
		used[save]--;
		used[a[i]]++;
			
		}
//		cout<<"#"<<i<<endl;
//	rb(i,1,n){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	rb(i,1,2*n){
//		if(used[i]){
//			cout<<i<<"-"<<used[i]<<endl;
//		}
//	}
//	cout<<endl;
	}
	cout<<rest.size()<<endl;
	for(auto it:rest) cout<<it<<" ";
	cout<<endl;
}
int main(){
	int t;
	R(t);
	while(t--) solve();
	return 0;
}