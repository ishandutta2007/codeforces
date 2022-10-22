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
8. CSPday2 meal
9.-or
10.
11.
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
int n,m;
LL need[100000+10];
vector<int> pos,neg;
bool cmp(int a,int b){
	return need[a]>need[b];
}
int main(){
	cin>>n>>m;
	rb(i,1,m){
		int u,v;
		int d;
		scanf("%d %d %d",&u,&v,&d);
		need[v]+=d;
		need[u]-=d;
	}
	rb(i,1,n)
		{
			if(need[i]<=0){
				need[i]*= -1;
				neg.PB(i);
			}
			else{
				pos.PB(i);
			}
		}
	int p1,p2;
	p1=p2=0;
	vector<pair<mp,LL> >  v;
	while(p1<neg.size()&&p2<pos.size()){
		int a,b;
		a=neg[p1];
		b=pos[p2];
		LL tmp=min(need[a],need[b]);
		need[a]-=tmp;
		need[b]-=tmp;
		if(tmp)
		v.PB(II(II(a,b),tmp));
		if(!need[a]){
			p1++;
		}
		if(!need[b]){
			p2++;
		}
	}
	cout<<v.size()<<'\n';
	for(auto it:v){
		printf("%d %d %I64d\n",it.FIR.FIR,it.FIR.SEC,it.SEC);
	}
	return 0;
	
}