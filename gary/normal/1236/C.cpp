/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
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
int res[500][500];
int main(){
	int n;
	cin>>n;
	int l,r;
	l=0,r=n*n+1;
	rb(i,1,n/2){
		rb(j,1,n){
			res[j][i]=++l;
			res[j][n-i+1]=--r;
		}
	}
	if(n&1){
		rb(i,1,n){
			res[i][n/2+1]=++l;
		}
	}
	rb(i,1,n)
	{
		rb(j,1,n) cout<<res[i][j]<<" " ;cout<<endl;
	}
	return 0;
}