/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,x0,y0,x[25],y[25],dp[1<<24],fir[1<<24];
int dis(int x1,int y1,int x2=x0,int y2=y0){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void update(int &a,int b){
	a=min(a,b);
}
int las[1<<24];
int main(){
	fastio;
	cin>>x0>>y0;
	cin>>n;
	rb(i,1,n){
		cin>>x[i]>>y[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	rep(i,1<<n)
		if(i!=1<<n)
		rep(j,n)
			if(!(i&(1<<j))){
				fir[i]=j+1;
				break;
			}
	rep(i,1<<n){
		if(i==(1<<n)-1){
			break; 	
		}
		if(dp[i]!=INF){
			if(dp[i^(1<<(fir[i]-1))]>dp[i]+(dis(x[fir[i]],y[fir[i]])<<1)){
				las[i^(1<<(fir[i]-1))]=i;
			}
			update(dp[i^(1<<(fir[i]-1))],dp[i]+(dis(x[fir[i]],y[fir[i]])<<1));
		rep(j,n){
			if(j+1!=fir[i]&&!(i&(1<<j))){
				if(dp[(i^(1<<(fir[i]-1)))+(1<<j)]>dp[i]+dis(x[fir[i]],y[fir[i]])+dis(x[fir[i]],y[fir[i]],x[j+1],y[j+1])+dis(x[j+1],y[j+1])){
					las[(i^(1<<(fir[i]-1)))+(1<<j)]=i;
				}
				update(dp[(i^(1<<(fir[i]-1)))+(1<<j)],dp[i]+dis(x[fir[i]],y[fir[i]])+dis(x[fir[i]],y[fir[i]],x[j+1],y[j+1])+dis(x[j+1],y[j+1])); 
			}
		}
		}
		
	}
	cout<<dp[(1<<n)-1]<<endl;
	int tmp=(1<<n)-1;
//	cout<<tmp<<endl;
//	cout<<las[tmp]<<endl;
	while(tmp){
		cout<<"0 ";
		int L=las[tmp];
		rep(i,n)
		{
//			cout<<endl<<((1<<i))<<"L"<<L<<" "<<i<<" "<<tmp<<endl;
			if(bool(L&(1<<i))+bool(tmp&(1<<i))==1){
				cout<<i+1<<" "; 
			}
		}
		tmp=L; 
	}cout<<"0";
	return 0;
}