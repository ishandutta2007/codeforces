/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
char maze[102][102];
struct ope{
	int x,y,xx,yy,xxx,yyy;
	ope(int a,int b,int c,int d,int f,int e){
		x=a;
		y=b;
		xx=c;
		yy=d;
		xxx=f;
		yyy=e;
	}
};
int a[102][102];
vector<ope> v;
void clean(int x,int y){
	if(a[x][y]+a[x][y+1]+a[x+1][y+1]+a[x+1][y]==0) return;
	if(a[x][y]+a[x][y+1]+a[x+1][y+1]+a[x+1][y]==3){
		vector<mp> vv;
		rep(i,2)
			rep(j,2)
				if(a[i+x][j+y]!=0){
					a[i+x][j+y]=0;
					vv.PB(II(i+x,j+y));
				}
		v.PB(ope(vv[0].FIR,vv[0].SEC,vv[1].FIR,vv[1].SEC,vv[2].FIR,vv[2].SEC));
		return;
	}
	if(a[x][y]+a[x][y+1]+a[x+1][y+1]+a[x+1][y]==4){
		a[x][y]^=1;
		a[x+1][y]^=1;
		a[x][y+1]^=1;
		v.PB(ope(x,y,x+1,y,x,y+1));
		clean(x,y);
		return;
	}
	if(a[x][y]+a[x][y+1]+a[x+1][y+1]+a[x+1][y]==2){
		if(a[x][y]==a[x][y+1]){
			if(a[x][y]==0){
				v.PB(ope(x,y,x+1,y,x,y+1));
				a[x][y]^=1;
				a[x][y+1]^=1;
				a[x+1][y]^=1;
				clean(x,y);
			}
			else{
				v.PB(ope(x,y,x+1,y+1,x+1,y));
				a[x][y]^=1;
				a[x+1][y+1]^=1;
				a[x+1][y]^=1;
				clean(x,y);
			}
		}
		else{
			if(a[x][y]==a[x+1][y+1]){
				if(a[x][y]==0){
					v.PB(ope(x,y,x+1,y+1,x,y+1));
					a[x][y]^=1;
					a[x][y+1]^=1;
					a[x+1][y+1]^=1;
					clean(x,y);
				}
				else{
					v.PB(ope(x,y,x+1,y,x,y+1));
					a[x][y]^=1;
					a[x+1][y]^=1;
					a[x][y+1]^=1;
					clean(x,y);
				}	
			} 
			else{
				if(a[x][y]==0){
					v.PB(ope(x,y,x+1,y,x,y+1));
					a[x][y]^=1;
					a[x][y+1]^=1;
					a[x+1][y]^=1;
					clean(x,y);
				}
				else{
					v.PB(ope(x,y,x+1,y+1,x,y+1));
					a[x][y]^=1;
					a[x+1][y+1]^=1;
					a[x][y+1]^=1;
					clean(x,y);
				}
			}
		}
		return;
	}
	if(a[x][y]+a[x][y+1]+a[x+1][y+1]+a[x+1][y]==1){
		if(a[x][y]){
			v.PB(ope(x,y,x,y+1,x+1,y+1));
				a[x][y]^=1;
				a[x][y+1]^=1;
				a[x+1][y+1]^=1;
		}
		else
		if(a[x+1][y+1]){
			v.PB(ope(x,y,x,y+1,x+1,y+1));
			a[x][y]^=1;
			a[x][y+1]^=1;
			a[x+1][y+1]^=1;
		}	
		else
		if(a[x][y+1]){
			v.PB(ope(x,y,x,y+1,x+1,y+1));
			a[x][y]^=1;
			a[x+1][y+1]^=1;
			a[x][y+1]^=1;
		}	
		else
		if(a[x+1][y]){
			v.PB(ope(x,y,x,y+1,x+1,y));
			a[x][y]^=1;
			a[x+1][y]^=1;
			a[x][y+1]^=1;
		}	
		clean(x,y);	
	}
} 
void solve(){
	cin>>n>>m;
	rb(i,1,n)
		rb(j,1,m)
			cin>>maze[i][j];
	rb(i,1,n)
		rb(j,1,m)
			a[i][j]=maze[i][j]-'0';
	v.clear();
	rb(i,1,n-2){
		rb(j,1,m){
			if(a[i][j]){
				if(j==1){
					a[i][j]^=1;
					a[i+1][j]^=1;
					a[i+1][j+1]^=1;
					v.PB(ope(i,j,i+1,j+1,i+1,j));
				}
				else{
					a[i][j]^=1;
					a[i+1][j]^=1;
					a[i+1][j-1]^=1;
					v.PB(ope(i,j,i+1,j,i+1,j-1));
				}
			}
		}
	}
	if(m%2==1){
		int i=n-1,j=m;
		if(a[n-1][m]){
			a[i][j]^=1;
			a[i][j-1]^=1;
			a[i+1][j]^=1;
			v.PB(ope(i,j,i,j-1,i+1,j));
		}
		i=n,j=m;
		if(a[n][m]){
			a[i][j]^=1;
			a[i][j-1]^=1;
			a[i-1][j-1]^=1;
			v.PB(ope(i,j,i,j-1,i-1,j-1));
		}
	} 
	for(int j=1;j<m;j+=2){
		clean(n-1,j);
	}
//	rb(i,1,n){
//		rb(j,1,m){
//			cout<<a[i][j];
//		}
//		cout<<endl;
//	}
	cout<<v.size()<<endl;
	assert(v.size()<=n*m);
	for(auto it:v){
		cout<<it.x<<' '<<it.y<<' '<<it.xx<<' '<<it.yy<<' '<<it.xxx<<' '<<it.yyy<<endl;
	}
}
int main(){
	fastio;
	int t;
	cin>>t;
	rb(i,1,t){
		solve();
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/