/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,a[100000+10],tot=0,isnt_prim[100000+10];
void init()
{
	isnt_prim[1]=1;
	rb(i,2,100000)
	{
		if(!isnt_prim[i]){
			for(int j=i*2;j<=100000;j+=i){
				isnt_prim[j]=1;
			}
		}
	}
}
LL res=100000000000000,tmp;
LL _cnt[100000+10];
void dp(int l,int r){
//	cout<<l<<" "<<r<<endl;
	int cnt=0;
	LL tmptmp=100000000000000;
	rb(i,l-1,r+1) _cnt[i]=0;
	rl(i,r,l){
		_cnt[i]=_cnt[i+1];
		_cnt[i]+=cnt;
		cnt+=a[i];
	} 
	cnt=0;
	LL tmptmp_=0;
	rb(i,l,r){
		tmptmp_+=cnt;
		tmptmp=min(tmptmp,_cnt[i]+tmptmp_);
		//cout<<i<<" "<<_cnt[i]+(LL)cnt<<" "<<_cnt[i]<<endl;
		cnt+=a[i];
	}
	tmp+=tmptmp;
}
void process(int x){
	tmp=0;
	int las=1,cnt=0;
	rb(i,1,n){
		cnt+=a[i];
		if(cnt==x){
			dp(las,i);
			las=i+1;
			cnt=0;
		}
	}
//	cout<<x<<" "<<tmp<<endl;
	res=min(res,tmp);
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]),tot+=a[i];
	if(tot==1){
		puts("-1");
		return 0;
	}
	if(!tot){
		puts("0");
		return 0;
	}
	init();
	for(int i=1;i*i<=tot;i++)
	{
		if(tot%i==0){
			int a=i,b=tot/i;
			if(!isnt_prim[a]){
				process(a);
			}
			if(!isnt_prim[b]){
				process(b);
			}
		}
	}
	cout<<res<<endl;
	return 0;
}