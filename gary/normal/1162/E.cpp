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
int a[55];
int main(){
	int n;
	cin>>n;
	rb(i,1,n) cin>>a[i];
	int win=1;
	rb(i,1,50){
		int cnt=0;
		rb(j,1,n) if(a[j]==i) cnt++;
		if(cnt){
		if(cnt>n/2){
			win^=1;
			
		}
		if(win==1){
			cout<<"Alice";
			return 0;
		}
		else{
			cout<<"Bob";
			return 0;
		}
			
		}
	}
	return 0;
}