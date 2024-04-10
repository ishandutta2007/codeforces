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
const int MAXN=6e3+1;
int n,x[MAXN],y[MAXN];
int cnt2[4][4];
int cnt[MAXN][4][4][4];
LL c[MAXN][4];
vector<int> conta[4][4];
int GG[4][4][4][4];
mp operator - (mp A,mp B){
	return II(A.FIR-B.FIR,A.SEC-B.SEC);
}
int operator * (mp A,mp B){
	return A.FIR*B.SEC-A.SEC*B.FIR;
}
int preg[MAXN][MAXN];
int main(){
	rep(i,4) rep(j,4) rep(k,4) rep(y,4) GG[i][j][k][y]=-1;
	scanf("%d",&n);
	rb(i,1,n) scanf("%d%d",&x[i],&y[i]);
	rb(i,1,n) rb(j,1,i) preg[i][j]=preg[j][i]=__gcd(abs(x[j]-x[i]),abs(y[j]-y[i]))&3;
	rb(i,1,n) rb(j,1,n) GG[x[i]&3][y[i]&3][x[j]&3][y[j]&3]=preg[i][j],cnt[i][x[j]&3][y[j]&3][preg[i][j]]++;
	rb(i,1,n) cnt2[x[i]&3][y[i]&3]++,conta[x[i]&3][y[i]&3].PB(i);
	rep(i,MAXN) c[i][0]=1;
	rb(i,1,MAXN-1) rb(j,1,3) (c[i][j]=c[i-1][j-1]+c[i-1][j]);
	LL ans=0;
	rep(ax,4) rep(ay,4)
	rep(bx,4) rep(by,4)
	rep(cx,4) rep(cy,4){
		if(II(ax,ay)<=II(bx,by)&&II(bx,by)<=II(cx,cy)){
			int ary=0;
			mp A,B,C;
			A=II(ax,ay);
			B=II(bx,by);
			C=II(cx,cy);
			ary=abs((A-C)*(B-C));
			if(!(ary&1)){
				int t=ary&3;
				if(A==C){
					ans+=c[cnt2[ax][ay]][3];
				}
				else if(A==B){
					rep(CA,4){
						int CB=(t+4-CA)&3;
						if(CA>CB) continue;
						for(auto it:conta[cx][cy])
						if(CA==CB){
							ans+=c[cnt[it][ax][ay][CA]][2];
						}
						else{
							ans+=cnt[it][ax][ay][CA]*cnt[it][bx][by][CB];
						}
					}
				}
				else if(B==C){
					rep(AC,4){
						int AB=(t+4-AC)&3;
						if(AC>AB) continue;
						for(auto it:conta[ax][ay])
						if(AC==AB){
							ans+=c[cnt[it][cx][cy][AC]][2];
						}
						else{
							ans+=cnt[it][cx][cy][AC]*cnt[it][bx][by][AB];
						}
					}
				}
				else{
					rep(AC,4) rep(AB,4){
						int CB=(t+8-AC-AB)&3;
						if(AC%2==0){
							if(AC==GG[ax][ay][cx][cy]){
								for(auto it:conta[bx][by]){
									ans+=cnt[it][ax][ay][AB]*cnt[it][cx][cy][CB];
								}
							}
						}
						else{
							if(AB%2==0){
								if(AB==GG[ax][ay][bx][by]){
									for(auto it:conta[cx][cy]){
										ans+=cnt[it][ax][ay][AC]*cnt[it][bx][by][CB];
									}
								}
							}
							else{
								if(CB==GG[bx][by][cx][cy]){	
									for(auto it:conta[ax][ay]){
										ans+=cnt[it][bx][by][AB]*cnt[it][cx][cy][AC];
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}