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
#define int LL
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
typedef pair<int,char> data;
int z[20000000+10];
void z_function(vector<data> S){
	int len=S.size();
	vector<data> v(1,II(INF,'^'));
	rep(i,len)
		v.PB(S[i]);
	S=v;
	int l,r;
	memset(z,0,sizeof(z));
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
int n,m;
signed main(){
	fastio;
	cin>>n>>m;
	vector<data> vv;
	data las=II(INF,'&');
	rb(i,1,n){
		data a;
		cin>>a.FIR>>a.SEC>>a.SEC;
		if(a.SEC==las.SEC){
			i--;
			n--;
			vv[vv.size()-1].FIR+=a.FIR;
		}
		else{
			las=a;
			vv.PB(a);	
		} 
	}
	vector<data> v2;
	las=II(INF,'&');
	rb(i,1,m){
		data a;
		cin>>a.FIR>>a.SEC>>a.SEC;
		if(a.SEC==las.SEC){
			i--;
			m--;
			v2[v2.size()-1].FIR+=a.FIR;
		}
		else{
			las=a;
			v2.PB(a);	
		} 
	}
	if(m<=2){
		LL res=0;
		if(m==1){
			rep(i,n){
				if(vv[i].SEC==v2[0].SEC)
				res+=max(0ll,vv[i].FIR-v2[0].FIR+1);		
			}
		}
		else{
			rep(i,n-1){
				if(vv[i].SEC==v2[0].SEC&&vv[i+1].SEC==v2[1].SEC){
					if(vv[i].FIR>=v2[0].FIR&&vv[i+1].FIR>=v2[1].FIR)
					res++;
				}
			}
		}
		cout<<res;
	}
	else{
		data head,tail;
		head=v2[0];
		tail=v2[v2.size()-1];
		v2.erase(v2.begin());
		v2.POB();
		v2.PB(II(INF,'&'));
		int tmp=v2.size();
		for(auto it:vv){
			v2.PB(it);
		} 
		z_function(v2);
		int res=0; 
		rb(i,tmp+1,v2.size()){
			if(z[i]==m-2&&v2[i+m-3].FIR>=tail.FIR&&v2[i-2].FIR>=head.FIR&&v2[i-2].SEC==head.SEC&&v2[i+m-3].SEC==tail.SEC){
			 	res++;
			} 
		}
		cout<<res<<endl;
	}
	return 0;
}