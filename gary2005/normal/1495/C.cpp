/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,m;
char c[505][505];
int cas=0;
void solve(){++cas;
	cin>>n>>m;
	rb(i,1,n){
		rb(j,1,m){
			cin>>c[i][j];
		}
	}
	rb(j,1,m){
		bool ok=0;
		rb(i,1,n){
			if(c[i][j]=='X'||(j!=m&&c[i][j+1]=='X')){
				ok=1;
			}
		}
		rb(i,1,n){
			c[i][j+2]='X';
		}
		if(j+2>m||j==1){
			rb(i,1,n){
				if(c[i][j]=='X'||(j!=m&&c[i][j+1]=='X')){
					c[i][j]=c[i][j+1]='X';
				}
			}
		}
		else{
			bool ok2=0;
			rb(i,1,n){
				if(c[i][j]=='X'||(j!=m&&c[i][j+1]=='X')){
					if(ok2) continue;
					c[i][j]=c[i][j+1]='X';
					ok2=1;
				}
			}
		}
		if(!ok){
			c[1][j]=c[1][j+1]='X';
		}
		j+=2;
	}
	if(m<=2){
		rb(i,1,n) c[i][1]='X';
	}
	rb(i,1,n){
		rb(j,1,m){
			cout<<c[i][j];
		}
		cout<<endl;
	}
}
int main(){
	fastio;
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}