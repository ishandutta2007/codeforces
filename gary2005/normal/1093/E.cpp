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
#define R(a) a=q()
#define R2(a,b) R(a),R(b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
inline int q(){
	int num=0;
	char c;
	c=getchar();
    while(c<'0'||c>'9') {
		c=getchar();
	}
    while(c>='0'&&c<='9'){
	num=num*10+(c^48);c=getchar();
	}
    return num;
}
const int MAGIC=1000,MAXN=200000+1,CNT=200;
int n,a[MAXN],b[MAXN],app[MAXN];
struct BIT{
int bit[MAXN]={0};
int sum(int i){
	int s=0;
		while(i>0){
			s+=bit[i];
			i-=i&(-i);
		}
		return s;
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+=i&(-i);	
		}
	}
}block[CNT+1];
int main(){
	fastio;
	R(n);
	int m;
	R(m);
	rb(i,1,n){
		R(a[i]);
		app[a[i]]=i;
	}
	rb(i,1,n)
	{
		R(b[i]);
		b[i]=app[b[i]];
	}
	rb(i,1,n){
		block[(i-1)/MAGIC+1].add(b[i]);
	}
	rb(Q,1,m){
		int ty;
		R(ty);
		if(ty==1){
			int la,ra,lb,rb;
			R2(la,ra);
			R2(lb,rb);
			int res=0;
			rb(i,lb,rb){
				if(i%MAGIC==1&&i+MAGIC-1<=rb){
					int id=i/MAGIC+1;
					res+=block[id].sum(ra)-block[id].sum(la-1);
					i+=MAGIC-1;					
				}
				else{
					res+=(b[i]<=ra&&b[i]>=la);
				}
			}
			cout<<res<<endl;
		} 
		else{
			int x,y;
			R2(x,y);
			int id=(x-1)/MAGIC+1;
			block[id].add(b[x],-1);
			id=(y-1)/MAGIC+1;
			block[id].add(b[y],-1);
			swap(b[x],b[y]);
			id=(x-1)/MAGIC+1;
			block[id].add(b[x]);
			id=(y-1)/MAGIC+1;
			block[id].add(b[y]);
		}
	}
	return 0;
}