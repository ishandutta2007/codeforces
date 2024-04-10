//* AuThOr GaRyMr *//
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
int r[1000+10],c[1000+10]; 
int gride[1000+10][1000+10],need[1000+10][1000+10];
int main(){
	int h,w;
	cin>>h>>w;
	rb(i,1,h) cin>>r[i];
	rb(j,1,w) cin>>c[j];
	rb(i,1,h){
		rb(j,1,r[i]+1){
			need[i][j]=1;
			if(j<=r[i]) {
//				cout<<i<<" "<<j<<endl;
				gride[i][j]=1;
			}
			else gride[i][j]=0;
		}
	} 
	rb(j,1,w){
		rb(i,1,c[j]+1){
			if(need[i][j]){
				if(i<=c[j]){
					if(gride[i][j]!=1){
//						cout<<i<<" "<<j<<endl;
						puts("0");
						return 0;
					}
				}
				else 
				{
					
					if(gride[i][j]!=0){
//						cout<<i<<" "<<j<<endl;
						puts("0");
						return 0;
					}
				}
			}
			else{
				need[i][j]=1;
				if(i<=c[j]) gride[i][j]=1;
				else gride[i][j]=0;
			}
		}
	}
	int MOD=1e9+7;
	LL res=1;
	rb(i,1,h)
		rb(j,1,w){
			if(!need[i][j]){
				res*=2;
				res%=MOD;
			}
		}
		cout<<res;
	return 0;
}