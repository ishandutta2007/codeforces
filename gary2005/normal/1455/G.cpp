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
int n,s;
int val[200000+20];
int del[200000+20]; 
map<int,LL> each[200000+20];
LL delta[200000+20];
multiset<LL> se[200000+20];
void upd(int id,int fi,LL val){
	if(each[id].find(fi)==each[id].end()){}
	else{
		se[id].erase(se[id].lower_bound(each[id][fi]));
	}
	each[id][fi]=val;
	se[id].insert(val);
}
LL fi(int id){
	return *se[id].begin();
}
void work(int st){
	int l,r;
	r=-del[st]-1;
	l=st+1;
	delta[st]=0;
	rb(i,l,r){
		if(del[i]<0){
			if(each[st].find(val[i])!=each[st].end()){
				se[i].insert(0);
				each[i][val[i]]=0;
				work(i);
				delta[i]+=each[st][val[i]]+delta[st];
	//			cout<<each[st][val[i]]<<' '<<delta[st]<<endl;
				if(each[st].size()<each[i].size()){
					for(auto ite=each[st].begin();ite!=each[st].end();ite++){
						if(ite->FIR!=val[i]){
							LL val_=ite->SEC+delta[st]-delta[i];
							if(each[i].find(ite->FIR)==each[i].end())
								upd(i,ite->FIR,val_);
							else{
								upd(i,ite->FIR,min(each[i][ite->FIR],val_));
							}
						}
					}
					each[st].swap(each[i]);
					swap(delta[i],delta[st]);
					se[i].swap(se[st]);
				}
				else{
					for(auto ite=each[i].begin();ite!=each[i].end();ite++){
						int New=ite->FIR;
						LL val_=ite->SEC+delta[i]-delta[st];
						if(each[st].find(New)==each[st].end()){
							upd(st,New,val_);
						}
						else{
							upd(st,New,min((New==val[i]? (LL)1e18:each[st][New]),val_));		
						}
					}
				}
				each[i].clear();
				se[i].clear(); 
			}
			i=-del[i];
			continue;
		}
			
		delta[st]+=del[i];
		if(val[i]==s) continue;
		int New=val[i];
		LL val_=fi(st)-del[i];
		if(each[st].find(New)==each[st].end()){
			upd(st,New,val_);
		}
		else{
			upd(st,New,min(each[st][New],val_));
		}
	}
}
int main(){
	scanf("%d%d",&n,&s);
	stack<int> pre;
	val[1]=0;
	del[1]=-(n+2);
	rb(i,2,n+1){
		string s;
		int y,v;
		cin>>s;
		if(s[0]=='s'){
			scanf("%d%d",&y,&v);
			val[i]=y;
			del[i]=v;
		}
		if(s[0]=='i'){
			scanf("%d",&y);
			val[i]=y;
			pre.push(i);
		}
		if(s[0]=='e'){
			val[i]=-1;
			del[pre.top()]=-i;
			pre.pop();
		}
	}	
	n+=2;
	se[1].insert(0);
	each[1][0]=0;
	work(1);
	cout<<fi(1)+delta[1]<<endl;
	return 0;
}
/*

25 1
set 1 2
set 1 10
if 0
end
set 1 8
if 1
set 0 9
set 0 10
if 1
if 0
end
end
set 1 7
set 1 7
set 1 9
set 0 5
set 1 8
set 1 2
end
if 0
set 0 3
if 1
end
set 0 4
end


*/