/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e6+1;
int bit[MAXN+10]={0};
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=MAXN){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
int bit2[MAXN+10]={0};
int sum2(int i){
	int s=0;
	while(i>0){
		s+=bit2[i];
		i-=i&(-i);
	}
	return s;
}
void add2(int i,int x=1){
	while(i<=MAXN){
		bit2[i]+=x;
		i+=i&(-i);	
	}
}
bool cmp1(mp A,mp B){
	return A.SEC>B.SEC;
}
bool cmp2(mp A,mp B){
	return A.SEC<B.SEC;
}
bool cmp3(pair<int,mp> A,pair<int,mp>  B){
	return A.FIR<B.FIR;
}
int main(){
	fastio;
	int n,m;
	vector<pair<int,mp> > heng,shu;
	R2(n,m);
	rb(i,1,n){
		int y,x,xx;
		R2(y,x);
		R(xx);
		y++;
		xx++;
		x++;
		heng.PB(II(y,II(x,xx)));
	}
	rb(i,1,m){
		int y,x,xx;
		R2(y,x);
		R(xx);
		y++;
		x++;
		xx++;
		shu.PB(II(y,II(x,xx)));
	}
	n+=2;
	m+=2;
	heng.PB(II(0+1,II(0+1,MAXN)));
	heng.PB(II(MAXN,II(1,MAXN)));
	shu.PB(II(1,II(1,MAXN)));
	shu.PB(II(MAXN,II(1,MAXN)));
	for(auto it:heng){
		add(it.FIR);
	}
	LL rest=0;
	rest=1ll*(n-1)*(m-1);
//	cout<<rest<<endl;
	for(auto it:shu){
		int l,r;
		l=it.SEC.FIR;
		r=it.SEC.SEC;
		if(l==1){
			if(r!=MAXN)
			rest-=n-sum(r);
		}
		else{
			if(l)
			rest-=sum(l-1);
		}
	}
//	cout<<rest<<endl;
	vector<pair<int,int > > to_r,to_l;
	for(auto it:heng){
		if(it.SEC.FIR==1){
			to_r.PB(II(it.FIR,it.SEC.SEC));
		}
		else{
			to_l.PB(II(it.FIR,it.SEC.FIR));
		}
	}
	sort(ALL(to_r),cmp1);
	sort(ALL(to_l),cmp2);
	sort(ALL(shu),cmp3);
	memset(bit,0,sizeof(bit));
	memset(bit2,0,sizeof(bit2));
	int now=shu.size();
	now--;
	for(auto it:to_r){
		while(now>=0&&shu[now].FIR>it.SEC){
			int l,r;
			l=shu[now].SEC.FIR;
			r=shu[now].SEC.SEC;
			if(l==1){
				add(r);
			}
			else{
				add2(l);
			}
			now--;
		}
		rest-=sum(MAXN)-sum(it.FIR-1);
		rest-=sum2(it.FIR);
	}
	memset(bit2,0,sizeof(bit2));
	memset(bit,0,sizeof(bit));
	now=0;
	for(auto it:to_l){
		while(now<shu.size()&&shu[now].FIR<it.SEC){
			int l,r;
			l=shu[now].SEC.FIR;
			r=shu[now].SEC.SEC;
			if(l==1){
				add(r);
			}
			else{
				add2(l);
			}
			now++;
		}
		rest-=sum(MAXN)-sum(it.FIR-1);
		rest-=sum2(it.FIR);
	}
	cout<<rest<<endl;
	return 0;
}