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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
map<mp,bool> bad;
vector<int> spr,spc;
map<int,int> sr,sc;
set<pair<mp,int> > se;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		int xi,yi;
		scanf("%d%d",&xi,&yi);
		bad[II(xi,yi)]=1;
		if(sr.find(xi)==sr.end()||sr[xi]>yi){
			sr[xi]=yi;
		}
		if(sc.find(yi)==sc.end()||sc[yi]>xi){
			sc[yi]=xi;
		}
		spr.PB(xi);
		spc.PB(yi);
	}
	spr.PB(INF+20);
	spc.PB(INF+20);
	sort(ALL(spr));
	sort(ALL(spc));
	int x,y;
	x=y=0;
	while(true){
		bool ok=false;
		do{
			ok=false;
			if(sr.find(x)!=sr.end()){
				if(sr[x]<y){
					x++;
					ok=true;
				}
			}
			if(sc.find(y)!=sc.end()){
				if(sc[y]<x){
					y++;
					ok=true;
				}
			}
		}while(ok);
		int len=min(*upper_bound(ALL(spr),x)-x,*upper_bound(ALL(spc),y)-y);
		len--;
		if(x+len+1==INF+20||y+len+1==INF+20){
			se.insert(II(II(x,x+len),x-y));
			break;
		}
		se.insert(II(II(x,x+len),x-y));
		x+=len+1;
		y+=len+1;
	}
	rb(i,1,m){
		int a,b;
		scanf("%d%d",&a,&b);
		bool ok=false;
		if(bad[II(a,b)]);
		else{
			auto ite=se.upper_bound(II(II(a,INF+50),INF));
			if(ite==se.begin()){
				ok=true;
			}
			else{
				ite--;
				if((ite->FIR).SEC>=a&&ite->SEC==a-b);
				else{
					ok=true;
				}
			}
		}
		puts(ok? "WIN":"LOSE");
	}
	return 0;
}