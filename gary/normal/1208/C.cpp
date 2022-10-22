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
int res[1001][1001];
int main(){
	int n;
	cin>>n;
	int fill=0;
	rb(i,1,n>>1)
		{
			rb(j,1,n>>1){
				res[i][j]=fill*4;
				res[i][j+(n>>1)]=fill*4+1;
				res[i+(n>>1)][j]=fill*4+2;
				res[i+(n>>1)][j+(n>>1)]=fill*4+3;fill++;
			}
			
		}
	rb(i,1,n){
		rb(j,1,n) cout<<res[i][j]<<" ";cout<<endl;	}
	return 0;
}