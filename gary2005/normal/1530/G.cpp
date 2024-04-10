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
const int MAXN=2e3+1;
int n,k;
string a,b;
pair<vector<int>,vector<mp> > solveodd(vector<int> v){
	v.resize(k+1);
	vector<mp> ope;
	int sum=0;
	for(auto it:v) sum+=it;
	sum+=k;
	rb(i,1,k){
		ope.PB(II(v[0]+1,sum));
		v[0]+=v.back();
		v.back()=0;
		reverse(v.begin()+1,v.end()-1);
		ope.PB(II(v[0]+v[1]+2,sum+1));
		reverse(v.begin()+2,v.end());
	}
	return II(v,ope);
}
pair<vector<int>,vector<mp> > solveeven(vector<int> v){
	v.resize(k+2);
	int sum=0;
	for(auto it:v){
		sum+=it;
	}
	sum+=k+1;
	vector<mp> ope;
	rb(i,1,k){
		ope.PB(II(v[0]+1,sum-1-v.back()));
		v[0]+=v[k];
		v[k]=0;
		reverse(v.begin()+1,v.end()-2);
		ope.PB(II(v[0]+2,sum-v.back()));
		v[k+1]+=v[1];
		v[1]=0;
		reverse(v.begin()+2,v.end()-1);
	}
	return II(v,ope);
}
pair<vector<int> ,vector<mp> > solve(vector<int> v){
	// 1. reverse k-1
	// 2. move i -> i+k
	vector<mp> prework;
	rl(i,v.size()-1,k){
		if(v[i]){
			int sum=0;
			int sum2=0;
			rb(j,0,i-k){
				sum+=v[j];
				sum++;
			}
			rb(j,0,i){
				sum2+=v[j];
				sum2++;
			}
			sum2--;
			prework.PB(II(sum,sum2));
			reverse(v.begin()+i-k+1,v.begin()+i);
			v[i-k]+=v[i];
			v[i]=0;
		}
	}
	if(k&1){
		// move all to 0
		auto ret=solveodd(v);
		for(auto it:ret.SEC){
			prework.PB(it);
		}
		ret.SEC=prework;
		return ret;
	}
	else{
		// move all to 0/k+1
		auto ret=solveeven(v);
		for(auto it:ret.SEC){
			prework.PB(it);
		}
		ret.SEC=prework;
		return ret;
	}
}
void solve(){
	scanf("%d%d",&n,&k);
	cin>>a>>b;
	if(k==0){
		if(a==b) puts("0");
		else puts("-1");
		return ;
	}
	vector<int> va,vb;
	int cnt=0;
	rep(i,n){
		if(a[i]=='1'){
			va.PB(cnt);
			cnt=0;
		}
		else{
			++cnt;
		}
	}
	va.PB(cnt);
	cnt=0;
	rep(i,n){
		if(b[i]=='1'){
			vb.PB(cnt);
			cnt=0;
		}
		else{
			++cnt;
		}
	}
	vb.PB(cnt);
	cnt=0;
	if(va.size()!=vb.size()){
		puts("-1");
		return ;
	}
	if(k>=va.size()){
		if(a==b) puts("0");
		else puts("-1");
		return ;
	}
	if(k+1==va.size()){
		rep(i,va[0]+1){
			rep(j,va.back()+1){
				if(i&&j) continue;
				string tmp=a;
				reverse(tmp.begin()+i,tmp.end()-j);
				if(tmp==b){
					puts("1");
					printf("%d %d\n",i+1,tmp.size()-j);
					return ;
				}
				int x,y;
				rep(i,tmp.size()) if(tmp[i]=='1'){
					x=i;
					break;
				}
				rep(i,tmp.size()) if(tmp[i]=='1') y=i;
				reverse(tmp.begin()+x,tmp.begin()+y+1);
				if(tmp==b){
					puts("2");
					printf("%d %d\n%d %d\n",i+1,tmp.size()-j,x+1,y+1);
					return ;
				}
			}
		}
		puts("-1");
		return ;
	}
	auto A=solve(va);
	auto B=solve(vb);
	if(A.FIR!=B.FIR){
		puts("-1");
		return ;
	}
	vector<mp> ans=A.SEC;
	reverse(ALL(B.SEC));
	for(auto it:B.SEC) ans.PB(it);
	printf("%d\n",ans.size());
	for(auto it:ans){
		printf("%d %d\n",it.FIR,it.SEC);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}