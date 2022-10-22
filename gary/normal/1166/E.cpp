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
int each[55][10000+10][2];
int main(){
	int n,m;
	//n<=1e4,m<=50
	cin>>m>>n;
	rb(i,1,m){
		int si;
		cin>>si;
		rb(j,1,si){
			int num;
			scanf("%d",&num);
			each[i][num][0]=1;
		}
		rb(j,1,n){
			each[i][j][1]=!each[i][j][0];
		}
	}
	rb(i,1,m){
		rb(j,1,m){
			int OK=1;
			rb(k,1,n){
				if(each[i][k][0]){
					if(each[j][k][1]);
					else OK=0;
				}
				
				
			}
			if(OK){
				puts("impossible");
				return 0;
			}
		}
	}
	puts("possible");
	return 0;
}