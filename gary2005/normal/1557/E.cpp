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
bool ok[10][10];
int n=8;
int cnt=0;
void move(string s,int x,int y){
	++cnt;
	if(cnt>=130) while(1);
	bool nw[10][10];
	rb(i,1,8) rb(j,1,8) nw[i][j]=0;
	rb(i,1,8) rb(j,1,8) if(ok[i][j]){
		if(s=="Right") nw[i][j+1]=1;
		if(s=="Left") nw[i][j-1]=1;
		if(s=="Up") nw[i-1][j]=1;
		if(s=="Down") nw[i+1][j]=1;
		if(s=="Down-Right") nw[i+1][j+1]=1;
		if(s=="Down-Left") nw[i+1][j-1]=1;
		if(s=="Up-Left") nw[i-1][j-1]=1;
		if(s=="Up-Right") nw[i-1][j+1]=1;
	}
	rb(i,1,8) nw[x][i]=0;
	rb(i,1,8) nw[i][y]=0;
	rb(i,-min(x,y)+1,n-max(x,y)){
		nw[x+i][y+i]=0;
	}
	rb(i,max(1-y,x-n),min(n-y,x-1)){
		nw[x-i][y+i]=0;
	}
	rb(i,1,n) rb(j,1,n) ok[i][j]=nw[i][j];
}
SRAND;
int rang(int l,int r){
	int tmp=r-l+1;
	return random(tmp)+l;
}
mp ran(mp tmp){
	if(random(2)){
		mp res;
		res=tmp;
		int tmp_=tmp.FIR;
		while(res.FIR==tmp_) res.FIR=rang(1,n);
		return res;
	}
	else{
		mp res;
		res=tmp;
		int tmp_=tmp.SEC;
		while(res.SEC==tmp_) res.SEC=rang(1,n);
		return res;
	}
}
mp find(mp from,string s){
	if(s=="Right") from.SEC++;
	if(s=="Left") from.SEC--;
	if(s=="Up") from.FIR--;
	if(s=="Down") from.FIR++;
	if(s=="Down-Right") from.FIR++,from.SEC++;
	if(s=="Down-Left") from.FIR++,from.SEC--;
	if(s=="Up-Left") from.FIR--,from.SEC--;
	if(s=="Up-Right") from.FIR--,from.SEC++;
	return from;
}
void solve(){
	cnt=0;
	rb(i,1,8) rb(j,1,8) ok[i][j]=1;
	mp p;
	p=II(1,1);
	cout<<p.FIR<<" "<<p.SEC<<endl;ff;
	rb(i,1,30){
		string tmp;
		cin>>tmp;
		if(tmp=="Done"){
			return ;
		}
		move(tmp,p.FIR,p.SEC);
		p=ran(p);
		cout<<p.FIR<<" "<<p.SEC<<endl;ff;
	}
	string tmp;
	cin>>tmp;
	if(tmp=="Done"){
		return ;
	}
	move(tmp,p.FIR,p.SEC);
	rb(i,1,8){
		rb(j,1,8){
			if(ok[i][j]){
				p.FIR=i;
				cout<<p.FIR<<' '<<p.SEC<<endl;ff;
				mp target=II(i,j);
				string tmp;
				cin>>tmp;
				if(tmp=="Done"){
					return ;
				}
				move(tmp,p.FIR,p.SEC);
				target=find(target,tmp);
				while(true){
					if(!ok[target.FIR][target.SEC]) break;
					if(target.SEC<p.SEC){
						p.FIR=target.FIR;
						p.SEC--;
						cout<<p.FIR<<' '<<p.SEC<<endl;ff;
						string tmp;
						cin>>tmp;
						if(tmp=="Done"){
							return ;
						}
						move(tmp,p.FIR,p.SEC);
						target=find(target,tmp);
					}
					else{
						p.FIR=target.FIR;
						p.SEC++;
						cout<<p.FIR<<' '<<p.SEC<<endl;ff;
						string tmp;
						cin>>tmp;
						if(tmp=="Done"){
							return ;
						}
						move(tmp,p.FIR,p.SEC);
						target=find(target,tmp);
					}
				}
			}
		}
	}
	assert(0);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}