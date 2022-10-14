/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
*/
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
void solve(){
	int OK[101]={0},a[101],pos[101];
	int n;
	cin>>n;
	rb(i,1,n) cin>>a[i],pos[a[i]]=i;
	rb(i,1,n){
		rl(j,pos[i]-1,1){
			if(a[j]<i) break; 
			if(OK[j]) break;
			OK[j]=1;
			swap(a[j],a[j+1]);
			pos[a[j]]++;
		}
	}
	rb(i,1,n) cout<<a[i]<<" ";cout<<endl;
}
int main(){
	int q;
	cin>>q;
	while(q--){
		solve();
	}
	return 0;
}