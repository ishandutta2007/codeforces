/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

int test; 

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d",&test);
	while(test--){
		int a,b;
		scanf("%d%d",&a,&b);
		int c=a,d=b;
		int ans1=-1,ans2=-1;
		vector<pii>ans;
		rep(wa,4)rep(sa,wa+1)rep(wb,(5-wa))rep(sb,wb+1)rep(wa5,2)rep(wb5,(2-wa5))rep(s5,2){
			a=c;b=d;
			if(wa+wa5>3||wb+wb5>3)continue;
			if((wa==3||wb==3||wa+wb<4)&&(wa5||wb5||s5))continue;
			if(wa+wa5!=3&&wb+wb5!=3)continue;
			if(!wa5&&!wb5&&s5)continue;
//			cout<<wa<<" "<<sa<<" "<<wb<<" "<<sb<<" "<<wa5<<" "<<wb5<<" "<<s5<<endl;
			int basea=wa*25+sa+sb*24;
			int baseb=sa*24+wb*25+sb;
			if(wa5){
				if(s5)basea+=16,baseb+=14;
				else basea+=15;
			}
			else if(wb5){
				if(s5)basea+=14,baseb+=16;
				else baseb+=15;
			}
			if(basea>a||baseb>b)continue;
			a-=basea;b-=baseb;
			if(sa||sb||s5){
				if(a>b){
					a-=b;
					int tot=(wb-sb)*23+((wb5&&!s5)?13:0);
					if(a>tot)continue;
				}
				else{
					b-=a;
					int tot=(wa-sa)*23+((wa5&&!s5)?13:0);
					if(b>tot)continue;
				}
			} 
			else{
				int tota=wb*23+((wb5)?13:0);
				int totb=wa*23+((wa5)?13:0);
				if(a>tota||b>totb)continue;
			}
			if(ans1<0||(wa+wa5-(wb+wb5))>ans1-ans2){
				ans1=wa+wa5;ans2=wb+wb5;
//				if(ans1==2&&ans2==3)cout<<wa<<" "<<sa<<" "<<wb<<" "<<sb<<" "<<wa5<<" "<<wb5<<" "<<s5<<endl; 
				ans.clear();
				a=c;b=d;
				if(sa||sb||s5){
					rep(i,sa)ans.pb(mp(26,24));
					rep(i,sb)ans.pb(mp(24,26));
					rep(i,wa-sa)ans.pb(mp(25,0));
					rep(i,wb-sb)ans.pb(mp(0,25));
					rep(i,wa5-s5)ans.pb(mp(15,0));
					rep(i,wb5-s5)ans.pb(mp(0,15));					
					rep(i,s5)ans.pb(wa5?mp(16,14):mp(14,16));
					a-=basea;b-=baseb;
					if(a>b){
						a-=b;
						for(int i=sa+sb+wa-sa;i<sa+sb+wa-sa+wb-sb;i++){
							int tmp=min(a,23);
							ans[i].fst=tmp;
							a-=tmp;
						}
						if(a){
							assert(wb5&&!s5);
							ans.back().fst=a;
						}
						if(sa||sb)ans[0].fst+=b,ans[0].snd+=b;
						else ans.back().fst+=b,ans.back().snd+=b;
					}
					else{
						b-=a;
						for(int i=sa+sb;i<sa+sb+wa-sa;i++){
							int tmp=min(b,23);
							ans[i].snd=tmp;
							b-=tmp;
						}
						if(b){
							assert(wa5&&!s5);
							ans.back().snd=b;
						}
						if(sa||sb)ans[0].fst+=a,ans[0].snd+=a;
						else ans.back().fst+=a,ans.back().snd+=a;
					}
				}
				else{
					a-=basea;b-=baseb;
					rep(i,wa)ans.pb(mp(25,0));
					rep(i,wb)ans.pb(mp(0,25));
					rep(i,wa5)ans.pb(mp(15,0));
					rep(i,wb5)ans.pb(mp(0,15));
					for(int i=wa;i<wa+wb;i++){
						int tmp=min(a,23);
						ans[i].fst=tmp;
						a-=tmp;
					}
					if(a){
						assert(wb5);
						ans.back().fst=a;
					}
					for(int i=0;i<wa;i++){
						int tmp=min(b,23);
						ans[i].snd=tmp;
						b-=tmp;
					}
					if(b){
						assert(wa5);
						ans.back().snd=b;
					}
				}
			}
		}
		if(ans1<0)puts("Impossible");
		else{
			printf("%d:%d\n",ans1,ans2);
			vector<pii>wa,wb;
			rep(i,ans.size())if(ans[i].fst>ans[i].snd)wa.pb(ans[i]);else wb.pb(ans[i]);
			assert(wa.size()==ans1&&wb.size()==ans2&&ans1+ans2<=5&&ans1<=3&&ans2<=3);
			int sz=min(wa.size(),wb.size());
			rep(i,sz){
				printf("%d:%d ",wa[i].fst,wa[i].snd);
				printf("%d:%d ",wb[i].fst,wb[i].snd);
			}
			for(int i=sz;i<wa.size();i++)printf("%d:%d ",wa[i].fst,wa[i].snd);
			for(int i=sz;i<wb.size();i++)printf("%d:%d ",wb[i].fst,wb[i].snd);
			puts("");
		}
	}
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/