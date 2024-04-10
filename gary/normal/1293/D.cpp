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
LL x0,y0,ax,ay,bx,by,xs,ys,t;
vector<pair<LL,LL > > pt; 
int main(){
	int res=0;
	fastio;
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	LL nowx,nowy;
	nowx=x0*ax+bx,nowy=y0*ay+by;
	pt.PB(II(x0,y0));
	while(nowx-xs<=t&&nowy-ys<=t&&nowx>0&&nowy>0){
		pt.PB(II(nowx,nowy));
//		cout<<nowx<<" "<<nowy<<endl;
		nowx=nowx*ax+bx,nowy=nowy*ay+by;
//		cout<<nowx<<"_"<<nowy<<endl;
	}
	int SZ=pt.size();
//	cout<<SZ<<endl;.
	rep(i,SZ){
		LL tmpt;
		int tmpres=0;
		tmpt=abs(xs-pt[i].FIR)+abs(ys-pt[i].SEC);
		if(tmpt==t){
			res=max(res,1);
		}
		if(tmpt<t){
			tmpres++;
			rl(j,i-1,0){
				if(abs(pt[i].FIR-pt[j].FIR)+abs(pt[i].SEC-pt[j].SEC)>t-tmpt){
					break;
				}
				tmpres++;
			}
			res=max(tmpres,res); 
			tmpres=1;
			rb(j,i+1,max(0,SZ-1)){
				if(abs(pt[i].FIR-pt[j].FIR)+abs(pt[i].SEC-pt[j].SEC)>t-tmpt){
					break;
				}
				tmpres++;
			}
			res=max(tmpres,res); 
		}
//		cout<<i<<" "<<res<<" "<<tmpt<<endl;
	}
	cout<<res;
	return 0;
}