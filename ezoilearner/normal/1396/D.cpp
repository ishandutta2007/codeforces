#include<bits/stdc++.h>
using namespace std;
int Ans=0;
const int Mod=1000000007;
int n,K,L,sum;
#define Maxn 2005
#define cout cerr
set<int> s[Maxn];
set<int>::iterator it;
struct Point{
	int x,y,c;
	Point(){x=y=c=0;}
	Point(int _x,int _y,int _c){x=_x;y=_y;c=_c;}
	bool operator <(const Point &t)const{return x==t.x?y<t.y:x<t.x;}
}p[Maxn],d[Maxn];
bool cmp(Point t1,Point t2){return t1.y<t2.y;}
int pre[Maxn],nxt[Maxn];
pair<int,int> seq[Maxn<<1];
int cnt;
int tot[Maxn];

namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
}using namespace modular;

set<pair<int,int> > S;

void calc(int id){
	cnt=0;
	for(int i=1;i<=K;++i)s[i].clear();
	for(int i=id;i>=1;--i){
		d[i]=p[i];
		it=s[p[i].c].upper_bound(p[i].y);
		if(it!=s[p[i].c].end())nxt[i]=(*it);
		else nxt[i]=L+1;
		if(it!=s[p[i].c].begin()){
			it--;
			pre[i]=(*it);
		}else pre[i]=0;
		s[p[i].c].insert(p[i].y);
	}
	sort(d+1,d+id+1,cmp);
	for(int i=1;i<=id;++i)seq[++cnt]=make_pair(d[i].y,d[i].c);
	for(int i=1;i<=K;++i)seq[++cnt]=make_pair(L+1,i),tot[i]=1;
	int at=cnt;
	S.clear();
	S.insert(make_pair(seq[id].first+1,seq[at].first));
	sum=mul(L-seq[id].first,seq[at].first);
	for(int i=id;i>=1;--i){
		tot[seq[i].second]++;
		while(tot[seq[at].second]>1){
			tot[seq[at].second]--;
			at--;
		}
		if(i==1||seq[i].first!=seq[i-1].first){
			S.insert(make_pair(seq[i-1].first+1,seq[at].first));
			sum=add(sum,mul(seq[i].first-seq[i-1].first,seq[at].first));
		}
	}
	int res=0;
	for(int i=1;i<=id;++i){
		res=add(res,mul(p[i].x-p[i-1].x,dec(mul(L+1,L),sum)));
		if(nxt[i]==p[i].y||pre[i]==p[i].y)continue;
		pre[i]++;
		pair<int,int> p=make_pair(pre[i],0);
		set< pair<int,int> >::iterator tmp=S.upper_bound(p);
		int pig=tmp->first;
		tmp--;
		if(tmp->first==pre[i])pig=pre[i];
		int val=tmp->second;
		if(tmp->second >= nxt[i])continue;
		while(true){
			tmp=S.lower_bound(p);
			if(tmp->second>=nxt[i]){
				sum=add(sum,mul(nxt[i],tmp->first-p.first));
				sum=dec(sum,mul(pig-pre[i],val));
				S.insert(make_pair(pre[i],nxt[i]));
				break;
			}
			pair<int,int> p1=(*tmp);
			tmp++;pair<int,int> p2=(*tmp);
			sum=dec(sum,mul(p1.second,p2.first-p1.first));
			S.erase(p1);
		}
	}
	res=mul(res,p[id+1].x-p[id].x);
	Ans=add(Ans,res);
}

inline void rd(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

int main(){
	rd(n);rd(K);rd(L);
	for(int i=1;i<=n;++i){
		rd(p[i].x);rd(p[i].y);rd(p[i].c);
		p[i].x++;p[i].y++;
	}
	p[n+1].x=L+1;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i)
		if(i==n||p[i].x!=p[i+1].x)calc(i);
	printf("%d\n",Ans);
	return 0;
}