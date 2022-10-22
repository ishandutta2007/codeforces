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
int a[100][100];
vector<mp > v;
int main(){
	int n,m;
	cin>>n>>m;
	rb(i,1,n) 
		rb(j,1,m){
			cin>>a[i][j];
		}
	rb(i,1,n){
		rb(j,1,m){
			if(a[i][j]){
				if(a[i-1][j]&&a[i][j-1]&&a[i-1][j-1]){
					v.PB(II(i-1,j-1));
				}
				else if(a[i-1][j]&&a[i][j+1]&&a[i-1][j+1])
				{
					v.PB(II(i-1,j));
				}
				else if(a[i][j-1]&&a[i+1][j]&&a[i+1][j-1]){
					v.PB(II(i,j-1));
				}
				else if(a[i][j+1]&&a[i+1][j]&&a[i+1][j+1]){
					v.PB(II(i,j));
				}
				else{
					cout<<"-1";
					return 0;
				}
			}
		}
	}
	cout<<v.size()<<endl;
	rep(i,v.size()){
		cout<<v[i].FIR<<" "<<v[i].SEC<<endl;
	}
	return 0;
}