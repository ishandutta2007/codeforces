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
#define FREO freopen("check.out","r",stdin)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL x[2002],y[2002],c[2002],k[2002];
vector<pair< LL ,mp > > ed;
LL res=0;
int boss[2002];
int dsu(int x)
{
	if(boss[x]==x){
		return x;
	}
	return boss[x]=dsu(boss[x]);
}
vector<pair<LL,int> > each[2002];
vector<int> res1;
vector<mp >  res2,tmp2;
LL res_tmp;
vector<int> tmp1;
int main(){
//	FREO;
	int n;
	cin>>n;
	boss[0]=0;
	rb(i,1,n) boss[i]=i;
	rb(i,1,n) scanf("%I64d %I64d",&x[i],&y[i]);
	rb(i,1,n) scanf("%I64d",&c[i]);
	rb(i,1,n) scanf("%I64d",&k[i]);
	rb(i,1,n){
		rb(j,i+1,n){
			LL tmp=0;
			tmp=abs(x[i]-x[j])+abs(y[i]-y[j]);
			tmp*=(k[i]+k[j]);
			ed.PB(II(tmp,II(i,j)));
		}
	}
	rb(i,1,n) {
		ed.PB(II(c[i],II(0,i)));
	}
	sort(ALL(ed));
	int sz=ed.size();
	rep(i,sz){
		int x1,y1;
		x1=ed[i].SEC.FIR;
		y1=ed[i].SEC.SEC;
		if(dsu(x1)!=dsu(y1)){
			boss[dsu(x1)]=dsu(y1);
			res+=ed[i].FIR;
			each[x1].PB(II(ed[i].FIR,y1));
			each[y1].PB(II(ed[i].FIR,x1));
		}
	}
	cout<<res<<endl; 
	for(auto it:each[0]){
		res1.PB(it.SEC);
	}
	cout<<res1.size()<<endl;
	for(auto it:res1){
		cout<<it<<" ";
	}cout<<endl;
	rb(i,1,n){
		for(auto it:each[i])
		{
			if(it.SEC){
				if(it.SEC<i)
				res2.PB(II(it.SEC,i));
			}
		}
	}
	cout<<res2.size()<<endl;
	for(auto it:res2){
		cout<<it.FIR<<" "<<it.SEC<<endl;
	}
	cout<<endl;
	return 0;
}