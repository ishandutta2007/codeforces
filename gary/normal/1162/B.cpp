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
int a[55][55],b[55][55];
int main(){
	int n,m;
	cin>>n>>m;
	rb(i,1,n) 
		rb(j,1,m) cin>>a[i][j];
	rb(i,1,n)
		rb(j,1,m) cin>>b[i][j];
	rb(i,1,n)
		rb(j,1,m){
			if(a[i][j]>b[i][j]) swap(a[i][j],b[i][j]);
		}
	rb(i,1,n){
		rb(j,1,m){
			rb(k,1,m){
				if(a[i][k]<=a[i][k-1]) {
					puts("Impossible");
					return 0;
				}	
				if(b[i][k]<=b[i][k-1]) {
					puts("Impossible");
					return 0;
				}
			}
			rb(k,1,n){
				if(a[k][j]<=a[k-1][j]) {
					puts("Impossible");
					return 0;
				}
				if(b[k][j]<=b[k-1][j]) {
					puts("Impossible");
					return 0;
				}
			}
		}
	}
	cout<<"Possible"<<endl;
	return 0;
}