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
const int MAXN=2e5+1;
const int MAGIC=400;
int n;
string s[MAXN];
string s2[MAXN];
vector<vector<int> > inc;  
vector<vector<unsigned LL> > pre;
vector<vector<unsigned LL> > suf;
int seed[26]; 
struct Hashtable{
	vector<pair<unsigned LL,unsigned LL> > ht;
	vector<int> nex;
	vector<int> val;
	int top[12345678];
	Hashtable(){
		fill(top,top+12345678,-1);
	}
	void add(pair<unsigned LL,unsigned LL> A){
		int hs=((A.FIR*123456ll)^A.SEC)%12345678;
		for(int now=top[hs];now!=-1;now=nex[now]){
			if(ht[now]==A){
				val[now]++;	
				return ;
			} 
		}
		int now=ht.size();
		nex.PB(top[hs]);
		ht.PB(A);
		val.PB(1);
		top[hs]=now;
	}
	int query(pair<unsigned LL,unsigned LL> A){
		int hs=((A.FIR*123456ll)^A.SEC)%12345678;
		for(int now=top[hs];now!=-1;now=nex[now]){
			if(ht[now]==A){
				return val[now];
			} 
		}
		return 0;
	}
}cnt;
const int MUL=1e9+3;
int tot[600][600];
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d",&n);
	inc.resize(n+1);
	pre.resize(n+1);
	suf.resize(n+1);
	rb(i,1,n){
		cin>>s[i];
		s[i]="a"+s[i]+"a";
		s2[i]=s[i];
		sort(ALL(s2[i]));
		inc[i].resize(s[i].length());
		rl(j,s[i].length()-1,0){
			if(j==s[i].length()-1)
			inc[i][j]=j;
			else{
				if(s[i][j]<=s[i][j+1]) inc[i][j]=inc[i][j+1];
				else inc[i][j]=j;
			}
		}
	}
	LL ans=0;
	if(n<=3000){
		rb(i,1,n)
			rb(j,i+1,n){
				if(s2[i]!=s2[j]){
					ans+=1337;
					continue;
				}
				int A=0,B=s[i].length()-1;
				while(s[i][A]==s[j][A]) ++A;
				while(s[i][B]==s[j][B]) --B;
				if(inc[i][A]>=B||inc[j][A]>=B){
					ans+=1;
				}
				else{
					ans+=2;
				}
			}
		printf("%lld\n",ans);
		return 0;
	}
	map<string,int> group;
	rb(i,1,n) group[s2[i]]++;
	ans=1ll*n*(n-1)/2*1337;
	for(auto ite=group.begin();ite!=group.end();ite++) ans-=1ll*ite->SEC*(ite->SEC-1)/2*(1337-2);
	rb(i,1,n){
		pre[i].resize(s[i].length());
		suf[i].resize(s[i].length());
		rep(j,s[i].length()){
			pre[i][j]=0;
			if(j){
				pre[i][j]=pre[i][j-1]*MUL;
			}
			pre[i][j]+=s[i][j];
		}
		rl(j,s[i].length()-1,0){
			suf[i][j]=0;
			if(j!=s[i].length()-1){
				suf[i][j]=suf[i][j+1]*MUL;
			}
			suf[i][j]+=s[i][j];
		}
		unsigned LL hs=0;
		rb(j,0,s[i].length()-1){
			hs*=MUL;
			hs+=s2[i][j];
		}
		for(auto &it:pre[i]){
			it*=hs;
		}
		rb(l,0,s[i].length()-1){
			rl(r,s[i].length()-1,l+1){
				cnt.add(II(pre[i][l],suf[i][r]));
			}
		}
	}
	rb(i,1,n){
		rb(l,0,s[i].length()-1){
			rl(r,s[i].length()-1,l+1){
				tot[l][r]=cnt.query(II(pre[i][l],suf[i][r]))-1;
			}
		}
		rb(l,0,s[i].length()-1){
			rl(r,s[i].length()-1,l+1){
				tot[l][r]-=tot[l][r-1];
				tot[l][r]-=tot[l+1][r];
				tot[l][r]+=tot[l+1][r-1];
			}
		}
		rb(l,0,s[i].length()-1){
			rl(r,s[i].length()-1,l+1){
				if(inc[i][l+1]>=r-1){
					ans-=tot[l][r];
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}