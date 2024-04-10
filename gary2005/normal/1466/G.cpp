/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
int n,q;
string s0,t;
int oc[26][100000+20];
vector<int> z;
void z_function(string S){
	int len=S.length();
	S='$'+S;
	int l,r;
	z.clear();
	z.resize(S.length()+22);
	rb(i,2,len)
		if(S[i]!=S[i-1]) break;
		else z[2]++;
	l=2,r=z[2]+1;
	rb(i,3,len){
		if(i<=r){
			z[i]=z[i-(l)+1];
			z[i]=min(z[i],r-i+1);
			if(z[i]+i-1==r){
				int ite=z[i]+1;
				rb(j,r+1,len){
					if(S[j]!=S[ite++]) break;
					z[i]++;
				}
				l=i,r=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(S[j]!=S[ite++]) break;
				z[i]++;
			}
			l=i,r=i+z[i]-1;
		}
	}
}
const int MOD=1e9+7;
bool can[101];
bool ok[101];
int pre[100000+20],inv2[100000+20];
int is;
int solve2(int l,string& tt,int now){
	if(now>l) return 0;
	if(tt.length()==1) 
	{
		int ret=(oc[tt[0]-'a'][now]-oc[tt[0]-'a'][l+1]+MOD)%MOD;
		ret=1ll*ret*inv2[n-l]%MOD;
		return ret;	
	}
	string od,ev;
	rep(i,tt.length()){
		if(i&1){
			od+=tt[i];
		}
		else{
			ev+=tt[i];
		}
	}
	bool ok=true;
	rep(i,od.length()) if(od[i]!=t[now-1]) {
		ok=false;
		break;
	}
	int ret=0;
	if(ok){
		ret+=solve2(l,ev,now+1);
	}
	ok=true;
	rep(i,ev.length()) if(ev[i]!=t[now-1]){
		ok=false;
		break;
	}
	if(ok){
		ret+=solve2(l,od,now+1);
		ret%=MOD;
	}
	return ret;
}
int solve(int l,string w){
	z_function(s0+'#'+w);
	memset(can,0,sizeof(can));
	rb(i,0,s0.length()) ok[i]=1;
	int len=w.length();
	rb(i,1,len){
		int now=s0.length()+1+i;
		if(z[now]==s0.length()||z[now]+i-1==len){
		}
		else{
			ok[i%(s0.length()+1)]=0;
		}
	} 
	reverse(ALL(w));
	reverse(ALL(s0));
	string tmp=s0+'$'+w;
	reverse(ALL(w));
	reverse(ALL(s0));
	z_function(tmp);
	rb(i,1,len+1){
		int now=s0.length()+1+i;
		if(z[now]+i-1==len){
			can[len-i+1]=1;
		}
	}
	int rest=0;
	rb(i,0,s0.length()){
		int st=i+2;
		if(can[i]&&ok[(st)%(s0.length()+1)]){
			string tt="";
			for(int j=st-1;j<=w.length();j+=s0.length()+1){
				tt+=w[j-1];
			}
			if(tt.length()!=0){
				rest+=solve2(l,tt,1);
				rest%=MOD;	
			}
		}
	}
	tmp=w+'$'+s0;
	z_function(tmp);
	int ttt=0;
	rb(i,1,s0.length()){
		if(z[i+w.length()+1]==w.length()){
			ttt++;
		}
	}
	ttt=1ll*ttt*pre[n]%MOD;
	ttt=1ll*ttt*inv2[n-l]%MOD;
	rest+=ttt;
	rest%=MOD;
	return rest;
}
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
int main(){
	scanf("%d%d",&n,&q);
	cin>>s0>>t;
	pre[0]=1;
	inv2[0]=1;
	inv2[1]=quick(2,MOD-2);
	rb(i,2,n) inv2[i]=1ll*inv2[i-1]*inv2[1]%MOD; 
	rb(i,1,n) pre[i]=(pre[i-1]+pre[i-1])%MOD;
	rl(i,n,0){
		rep(j,26){
			oc[j][i]=oc[j][i+1];
		}
		if(i)
			(oc[t[i-1]-'a'][i]+=pre[n-i])%=MOD;
	}
	rb(i,1,q){
		int k;
		string w;
		scanf("%d",&k);
		cin>>w;
		printf("%d\n",solve(k,w));
//		break;
	}
	return 0;
}