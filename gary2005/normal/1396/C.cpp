/*
{By GWj
*/
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
LL f[1000000+1][2];
int n,a[1000000+1];
LL r1,r2,r3,d;
LL half(int x){
	LL rest=r2;
	LL tmp=min(r1,r3)*x;
	tmp+=r1;
	return min(rest,tmp);
} 
LL two(int x){
	LL rest=min(r1,r3)*(x)+r3;
	return min(rest,half(x)+min(min(r1,r2),r3));
}
int main(){
	R(n);
	cin>>r1>>r2>>r3>>d;
	rb(i,1,n)
		R(a[i]);
	memset(f,127,sizeof(f));
	f[0][0]=0;
	rb(i,1,n){
		rep(j,2){
			if(j==0)
			{
				LL cost=f[i-1][0];
				if(f[i-1][0]<1e18){
					if(i!=1)
					cost+=d;
					cost+=1ll*a[i]*min(r1,r3);
					cost+=r3;
					f[i][j]=cost;
				}
				if(f[i-1][1]<1e18){
					cost=f[i-1][1];
					cost+=3ll*d;
					cost+=min(min(r1,r2),r3);
					cost+=two(a[i]);//
					check_min(f[i][j],cost);
				} 
			}
			else{
				LL cost=f[i-1][0];
				if(f[i-1][0]<1e18){
					if(i!=1)
					cost+=d;
					cost+=half(a[i]);// 
					f[i][1]=cost;
				}
				if(f[i-1][1]<1e18){
					cost=f[i-1][1];
					cost+=3ll*d;
					cost+=min(min(r1,r2),r3);
					cost+=half(a[i]);
					check_min(f[i][j],cost);	
				}
			}
		}
	}
	LL rest=f[n][0];
//	cout<<rest<<endl;
	LL tmp=min(r1,r3)*a[n]+r3;
	rl(i,n-1,1){
		tmp+=d*2;
		tmp+=two(a[i]);
//		cout<<tmp<< " "<<f[i-1][0]<<" "<<(i==1? 0:d)<<endl;
		if(tmp>=rest) break;
		rest=min(rest,tmp+(i==1? 0:d)+f[i-1][0]);
	}
	cout<<rest<<endl;
	return 0;
}