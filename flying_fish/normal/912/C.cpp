#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

int n,m,k,i;
LL bounty,increase,damage;
set<pair<int,pair<int,LL> > > T;
LL maxhealth[maxn],health[maxn],regen[maxn];
set<pair<LL,int>> S;//time,id;cntdefeat,ans++
bool added[maxn];//defeated
LL pos[maxn];//delpos
LL ans,now;
set<LL> times;
inline void add(int i,int t){
    if (!added[i]){
		now--;
//    	del[pos[i]].erase(i);
        S.erase(make_pair(pos[i],i));
    }added[i]=0;
    if (health[i]<=damage){
        if (regen[i]==0||maxhealth[i]<=damage) pos[i]=10000000001;
        else pos[i]=(damage-health[i])/regen[i]+t+1;
//        del[pos[i]].insert(i);
		if (pos[i]-1>t) times.insert(pos[i]-1);
		times.insert(pos[i]);
        S.insert(make_pair(pos[i],i));
		now++;
    }else added[i]=1;
//    printf("ADD: time:%d i:%d  pos:%d health:%d  now=%d\n",t,i,pos[i],health[i],now);
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%I64d%I64d%I64d",&bounty,&increase,&damage);
    FOR(i,1,n) scanf("%d%d%d",&maxhealth[i],&health[i],&regen[i]);
	FOR(i,1,m){
	    int time,enemy,health;
	    scanf("%d%d%d",&time,&enemy,&health);
	    T.insert(make_pair(time,make_pair(enemy,health)));
	    times.insert(time);times.insert(time-1);
	}
	FOR(i,1,n) added[i]=1;
	FOR(i,1,n) add(i,0);
	times.insert(10000000000);
	times.insert(0);
	while(times.size()){
		LL i=*times.begin();if (i==10000000000) break;
		times.erase(times.begin());
		while (T.size()&&(*T.begin()).first==i){
			auto F=*(T.begin());T.erase(T.begin());
			auto x=F.second;i=F.first;
	        health[x.first]=x.second;
	        add(x.first,i);
		}while (S.size()&&(*S.begin()).first==i){
        	int x=(*S.begin()).second;
        	S.erase(S.begin());
            added[x]=1;now--;
//			printf("del:%d    now=%d\n",x,now);
        }ans=max(ans,(bounty+increase*i)*now);
//        printf("time=%d ; ans=%d now=%d\n",i,ans,now);
	}if (now&&increase) printf("-1\n");
	else printf("%I64d\n",ans);
}
/*
*/