#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7,N=1000011;
const double eps=1e-6;
char *TT,*mo,but[(1<<15)+2];
#ifdef ONLINE_JUDGE
	#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)
#endif
struct node{
	ll x,y;
	ll dis(){
		return x*x+y*y;
	}
	node operator-(const node&t)const{
		return (node){x-t.x,y-t.y};
	} 
	void rd(){
		cin>>x>>y;
	}
} a,b,c;
bool slop(const node&i,const node&j){
	return i.x*j.y!=i.y*j.x;
}
int main(){
	a.rd(),b.rd(),c.rd();
	a=a-b,c=c-b;
	/*cout<<a.x<<" "<<a.y<<endl;
	cout<<c.x<<" "<<c.y<<endl;
	cout<<c.y*c.y<<endl;*/
	puts((a.dis()==c.dis()&&slop(a,c))?"YES":"NO");
}