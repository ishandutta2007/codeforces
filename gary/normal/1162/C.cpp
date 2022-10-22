//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int x[100000+10];
int A[100000+10],B[100000+10];
int res;
int have[100000+10][3];
int main(){
	int n,k;
	cin>>n>>k;
	rb(i,1,k) cin>>x[i],B[x[i]]++;
	rb(i,1,n){
		if(!B[i]) {
//			cout<<i<<" "<<i<<endl;
			have[i][1]=1;
			res++; 
		}
		if(!B[i+1]&&i+1<=n) {
//			cout<<i<<" "<<i+1<<endl;
			have[i][2]=1;
			res++;
		}
		if(!B[i-1]&&i-1>=1) {
//			cout<<i<<" "<<i-1<<endl;
			have[i][0]=1;
			res++;
		}
	}
	rb(i,1,k){
		B[x[i]]--;
		A[x[i]]++;
		if(!B[x[i]]){
			if(!A[x[i]-1]&&!have[x[i]-1][2]&&x[i]-1>=1){
//				cout<<x[i]-1<<" "<<x[i]<<endl;
				have[x[i]-1][2]=1;
				res++;
			}
			if(!A[x[i]+1]&&!have[x[i]+1][0]&&x[i]+1<=n){
//				cout<<x[i]+1<<" "<<x[i]<<endl;
				have[x[i]+1][0]=1;
				res++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}