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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<int,int> x;
pair<string,mp> q[200000];
inline int getint(){
    int r=0;
	char c;
	c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){r=r*10+c-'0';c=getchar();}
    return r;
}
 
struct node{
	set<int> s;//it is only used when seg[index] is a leaf!!
	int maxi=0;
};
int treen;
node segtree[200000*8];
int query(int a,int b,int val,int now=1,int l=1,int r=treen+1){
	if(r<=a||l>=b){
		return 0;
	}
	if(l==r-1){
		if(segtree[now].maxi>val){
			return l;
		}
		else{
			return 0;
		}
	}
	if(r<=b&&l>=a){
		if(segtree[now].maxi>val);
		else return 0;
	}
	int mid=(l+r)>>1;
	int L=query(a,b,val,now<<1,l,mid);
	if(L){
		return L;
	}
	int R=query(a,b,val,(now<<1)+1,mid,r);
	return R;
}
void change(int index,int val,bool ty){
	index+=treen-1;
	if(!ty){
		segtree[index].s.insert(val);	
	} 
	else{
		segtree[index].s.erase(val);
	}
	if(segtree[index].s.empty())
	segtree[index].maxi=0;
	else{
		set<int> :: IT ite=segtree[index].s.end();
		ite--;
		segtree[index].maxi=*ite;
	} 
	index>>=1;
	while(index){
		segtree[index].maxi=max(segtree[index<<1].maxi,segtree[(index<<1)+1].maxi);
		index>>=1;
	}
}
int real_[200000+20];
int main(){
	fastio;
	int n;
	cin>>n;
	treen=1<<(int)(ceil(log2(double(n))));
	rb(i,1,n){
		pair<string,mp> now;
		cin>>now.FIR>>now.SEC.FIR>>now.SEC.SEC;
//		cin>>now.FIR;
//		now.SEC.FIR=getint();
//		now.SEC.SEC=getint()
		q[i-1]=now;
		x[now.SEC.FIR]=1;
	}
	int cnt=1;
	for(map<int ,int > :: IT ite=x.begin();ite!=x.end();ite++,cnt++)	ite->SEC=cnt,real_[cnt]=ite->FIR;
	rb(i,1,n){
		q[i-1].SEC.FIR=x[q[i-1].SEC.FIR];
	}
	rb(i,1,n){
//		cout<<q[i-1].FIR<<endl;
		if((q[i-1].FIR)[0]=='a'){
			change(q[i-1].SEC.FIR,q[i-1].SEC.SEC,0);
		}
		else{
			if((q[i-1].FIR)[0]=='r'){
				change(q[i-1].SEC.FIR,q[i-1].SEC.SEC,1);
			}
			else{
				int X,Y;
				X=q[i-1].SEC.FIR;
				Y=q[i-1].SEC.SEC;
//				cout<<query(X+1,treen+1,Y)<<endl;
				if(!query(X+1,treen+1,Y)){
					cout<<-1<<endl;
				}
				else{
					int l=query(X+1,treen+1,Y);
					cout<<real_[l]<<" "<<(*(segtree[l+treen-1].s.upper_bound(Y)))<<endl;
				}
			}
		}
	}
	return 0;
}