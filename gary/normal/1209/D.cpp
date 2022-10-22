//* AuThOr GaRyMr *//
//Codeforces ID: GaryMr
//Atcoder ID: Gary
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int used[200000+10];
int a[100000+10],b[100000+10];
vector<int> have[200000+10];
int useguy[100000+10]={-1,1};
int res=0;
void dfs(int c1,int c2){
//	cout<<c1<<" "<<c2<<endl;
	for(auto it: have[c1]){
		if(!useguy[it]&&((!used[a[it]])||(!used[b[it]]))){
			useguy[it]=1,used[a[it]]=used[b[it]]=1;
			res++;
			if(a[it]!=c1){
				dfs(c2,a[it]);
			}
			else{
				dfs(c2,b[it]);
			}
		}
	}
	for(auto it: have[c2]){
		if(!useguy[it]&&((!used[a[it]])||(!used[b[it]]))){
			useguy[it]=1,used[a[it]]=used[b[it]]=1;
			res++;
			if(a[it]!=c2){
				dfs(c1,a[it]);
			}
			else{
				dfs(c1,b[it]);
			}
		}
	}
}
int main(){
	int n,k;
	/*snacks-gusets*/
	cin>>n>>k;
	rb(i,1,k){
//		cout<<endl<<i<<"*"<<endl;
		cin>>a[i]>>b[i];
		have[a[i]].PB(i),have[b[i]].PB(i);
	}
	rb(i,1,k)
	if(!used[a[i]]&&!used[b[i]]){
//		cout<<i<<" "<<" "<<a[i]<<" "<<b[i]<<endl;
		res++;
		used[a[i]]=used[b[i]]=1;
		useguy[i]=1;
		dfs(a[i],b[i]);	
	}
	cout<<k-res<<endl;
	return 0;
}