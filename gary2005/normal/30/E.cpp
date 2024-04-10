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
SRAND;
struct String_Hash{
	LL MUL=1e9+9,MOD=1e9+7;
	LL quick(LL A,LL B){
		if(!B) return 1ll;
		LL tmp=quick(A,B>>1);
		tmp*=tmp;
		tmp%=MOD;
		if(B&1){
			tmp*=A;
			tmp%=MOD;
		}
		return tmp;
	}
	LL val[26];
	LL num[100000+20],inv[100000+20];
	void init(){
		rep(i,100000)
			inv[i]=quick(quick(MUL,i),MOD-2); 
		rep(i,26){
			val[i]=random(1000000000)+1;
		}
	}
	void hash_work(string s){
		LL alr=1;
		rep(i,s.length())
		{
			num[i+1]=num[i]+val[s[i]-'a']*alr%MOD;
			num[i+1]%=MOD; 
			alr*=MUL;
			alr%=MOD;
		}
	}
	LL cut(int l,int r){
		return (num[r]-num[l-1]+MOD)%MOD*inv[l-1]%MOD;
	}
}hs,hs_rev;
const int N=1<<17;
mp segtree[N*2];
void change(int index,int val){
	index+=N-1;
	segtree[index]=max(segtree[index],II(val,index-(N-1)));
	index>>=1;
	while(index){
		segtree[index]=max(segtree[index<<1],segtree[index<<1|1]);
		index>>=1;
	} 
}
mp query(int a,int b,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return II(0,1);
	}
	if(r<=b&&l>=a){
		return segtree[now];
	}
	int mid=(l+r)>>1;
	return max(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
bool comp(mp A , mp B){
	return A.SEC>B.SEC;
}
int nxt[200000+20];
int main(){
	fastio;
	string s;
	R(s);
	hs.init();
	hs_rev.init();
	rep(i,26)
		hs_rev.val[i]=hs.val[i];
	hs.hash_work(s);
	string ss;
	ss=s;
	reverse(ALL(s));
	ss=s+'#'+ss;
	int j_=0;
	rep(i,ss.length()){
		if(!i) continue;
		if(ss[i]==ss[j_]){
			nxt[i]=++j_;
		}
		else{
			while(j_&&ss[i]!=ss[j_]){
				j_=nxt[j_-1];
			}
			if(ss[i]==ss[j_]){
				nxt[i]=++j_;
			}
			else{
				nxt[i]=0;
			}
		}
	}
	hs_rev.hash_work(s);
	vector<mp> can;	
	int len=s.length();
	s='#'+s;
	rb(i,1,len){
		can.PB(II(nxt[i+len],i));
	}
	sort(ALL(can));
	vector<mp> queries;
	rb(i,1,len){
		int l=1,r=min(len-i+1,i)+1;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(hs.cut(i,mid+i-1)==hs_rev.cut(len-i+1,len-i+1+mid-1)){
				l=mid;
			}
			else{
				r=mid;	
			}
		}
		queries.PB(II(i-l+1,i+l-1));
	}
	
	sort(ALL(queries),comp);
	pair<int,pair<mp,mp> > rest=II(-1,II(II(-1,-1),II(-1,-1)));
	int zz=0;
	for(auto it:queries){
		while(zz<can.size()&&can[zz].FIR<=len-it.SEC){
			change(can[zz].SEC,can[zz].FIR);
			zz++;
		}
		mp qq=query(1,it.FIR);
		if(it.SEC-it.FIR+1+qq.FIR*2>rest.FIR)
		rest=II(qq.FIR*2+it.SEC-it.FIR+1,II(it,qq));
	}	
	if(rest.SEC.SEC.FIR){
		cout<<3<<endl;
		cout<<rest.SEC.SEC.SEC-rest.SEC.SEC.FIR+1<<" "<<rest.SEC.SEC.FIR<<endl;
		cout<<rest.SEC.FIR.FIR<<" "<<rest.SEC.FIR.SEC-rest.SEC.FIR.FIR+1<<endl;
		cout<<len-rest.SEC.SEC.FIR+1<<" "<<rest.SEC.SEC.FIR<<endl; 
	}
	else{
		cout<<1<<endl;
		cout<<rest.SEC.FIR.FIR<<" "<<rest.SEC.FIR.SEC-rest.SEC.FIR.FIR+1<<endl; 
	}
//	cerr<<"#"<<rest.FIR<<endl;
	return 0;
}
/*
ababa

*/