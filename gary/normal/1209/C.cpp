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
int n,d[200000+10],color[200000+10],mini[200000+10];
void solve(){
	scanf("%d",&n);
	rb(i,1,n){
		char tmp;
		cin>>tmp;
		d[i]=tmp-'0';color[i]=0;
	}
	mini[n+1]=INF;
	rl(i,n,1) mini[i]=min(mini[i+1],d[i]);
	/*First is color two*/
	int las=-INF;
	rb(i,1,n){
		if(d[i]>=las) {
			color[i]=1;
			las=d[i];
		}
	}
	las=-INF;
	int OK=1;
	rb(i,1,n){
		if(!color[i]){
			if(d[i]<las){
				OK=0;
				break;
			}
			las=d[i];
		}
	}
	if(las>d[1]) OK=0;

	if(OK){
		rb(i,1,n) printf("%d",color[i]+1);puts("");
		return;
	}
	if(d[1]<=mini[2]){int fir=-1;
	OK=1;
	memset(color,0,sizeof(color));
	rb(i,1,n){
		if((fir==-1||d[i]<=fir)&&(d[i]<=mini[i+1])){
			color[i]=1;
		}	
		else if(fir==-1) fir=d[i];
	} 
//	cout<<fir<<endl;
//	rb(i,1,n) cout<<color[i]<<" "; 
	las=-INF;
	rb(i,1,n){
		if(!color[i]){
			if(d[i]>=las) las=d[i];
			else{
				OK=0;
				break;
			}
		}
	}
	if(OK){
		rb(i,1,n) printf("%d",(color[i]? 1:2));puts("");
		return;
	}	
	}
	puts("-");
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}