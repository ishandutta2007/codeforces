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
int pin[20000+10],dep[20000+10];int s1,s2,s3,s4,s5,s,t,n,b,q;
struct EDGE{
	int u,v,c;
};
vector<EDGE> e;
vector<int> each[20000+10];

bool bfs(){
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int now=Q.front();
//		cout<<dep[now]<<" "<<now<<endl;
		Q.pop();
		for(auto it:each[now]){
			int next=e[it].v;
			if(e[it].c)
			if(dep[next]>dep[now]+1){
				dep[next]=dep[now]+1;
				Q.push(next);
			}
		}
	}
//	cout<<t<<endl;
//	cout<<dep[t]<<endl;
	return dep[t]!=INF;
}
int dfs(int now,int flow){
	if(now==t){
		return flow;
	}
	for(int & i= pin[now];i<each[now].size();i++){
		int it=each[now][i];
		if(e[it].c&&dep[e[it].v]==dep[now]+1){
			int tmp;
			if(tmp=dfs(e[it].v,min(flow,e[it].c))){
				e[it].c-=tmp;
				e[it^1].c+=tmp;
				return tmp;
			}
		}
	}
	return 0;
}
int Dinic(){
	int max_flow=0;
	rep(i,20000+10)
	{
		if(i)
		dep[i]=INF;
	}
//	cout<<"I"<<endl;
	while(bfs()){
//		cout<<"d-d\n "; 
		rb(i,0,20000+9){
			pin[i]=0;
		}
		int tmp;
		while(tmp=dfs(s,INF)){
			max_flow+=tmp;
		}
		rb(i,1,20000+9){
			dep[i]=INF;
		}
	}
	return max_flow;
}
void make_edge(int U,int V,int C){
//	cout<<U<<" "<<V<<" "<<C<<endl;
//	cout<<U<<" "<<V<<" "<<C<<endl;
	EDGE tmp;
	tmp.u=U;
	tmp.v=V;
	tmp.c=C;
	e.PB(tmp);
	each[U].PB(e.size()-1);
	swap(tmp.u,tmp.v);
	tmp.c=0;
	e.PB(tmp);
	each[V].PB(e.size()-1);
}
struct HINT{
	int up_,qua_;
};
vector<HINT> h_set;
bool cmp(HINT A,HINT B){
	return A.up_<B.up_;
}
vector<HINT> LISAN;
int main(){
	cin>>n>>b>>q;
	rb(i,1,q){
		int UPP,QUA;
		scanf("%d %d",&UPP,&QUA);
		if(QUA>UPP){
			cout<<"unfair\n";
			return 0;
		}
		h_set.PB((HINT){UPP,QUA});
	}
	h_set.PB((HINT){b,n});
	sort(ALL(h_set),cmp);
	int SZ=h_set.size();
	int TOT=0;
	rep(i,SZ){
		if(i){
			if(h_set[i].qua_<h_set[i-1].qua_){
				cout<<"unfair\n";
				return 0;
			}
			if(h_set[i].up_==h_set[i-1].up_){
				if(h_set[i].qua_!=h_set[i-1].qua_){
					cout<<"unfair\n";
					return 0;
				}
			}
			else{
				TOT++;
				LISAN.PB(h_set[i]);
			}
		}
		else{
			TOT++;
			LISAN.PB(h_set[i]);
		}
		
	}
//	cout<<TOT<<endl;
	s=0;
	t=TOT+1;
	s1=t+1;
	s2=t+2;
	s3=t+3;
	s4=t+4;
	s5=t+5;
	SZ=LISAN.size();
	rep(i,SZ){
		if(i){
			make_edge(s,s5+i+1,LISAN[i].qua_-LISAN[i-1].qua_);
			int one,two,three,four,five;
			one=two=three=four=five=0;
			rb(j,LISAN[i-1].up_+1,LISAN[i].up_)
{
if(j%5==1){
	one++;
}
if(j%5==2){
	two++;
}
if(j%5==3){
	three++;
}
if(j%5==4){
	four++;
}
if(j%5==0){
	five++;
}
}
make_edge(s5+i+1,s1,one);
make_edge(s5+i+1,s2,two);
make_edge(s5+i+1,s3,three);
make_edge(s5+i+1,s4,four);
make_edge(s5+i+1,s5,five);

			}
		else{
			make_edge(s,s5+i+1,LISAN[i].qua_);
			int one,two,three,four,five;
			one=two=three=four=five=0;
			rb(j,1,LISAN[i].up_)
{
if(j%5==1){
	one++;
}
if(j%5==2){
	two++;
}
if(j%5==3){
	three++;
}
if(j%5==4){
	four++;
}
if(j%5==0){
	five++;
}
}
make_edge(s5+i+1,s1,one);
make_edge(s5+i+1,s2,two);
make_edge(s5+i+1,s3,three);
make_edge(s5+i+1,s4,four);
make_edge(s5+i+1,s5,five);
		}
	} 
	make_edge(s1,t,n/5);
	make_edge(s2,t,n/5);
	make_edge(s3,t,n/5);
	make_edge(s4,t,n/5);
	make_edge(s5,t,n/5);
	if(Dinic()==n){
		cout<<"fair";
	}
	else{
		cout<<"unfair";
	}
	return 0;
}