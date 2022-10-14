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
int n,m;
typedef bitset<1523> BS;
BS A[1505],B[1505];
int a[1505][1505],b[1505][1505];
int las[1505];
bool vis[1505];
vector<int> g[1505];
int se;
unsigned LL Hs(unsigned LL num,unsigned LL j){
	unsigned LL val=(num<<20)|(num<<40)|(num<<50);
	j*=se;
	j%=3333;
	j+=1234;
	val*=1299;
	val*=j*j;
	j*=num*val;
	val^=(j<<21)|(j<<41)|(j<<51);
	return val;
}
map<unsigned LL,queue<int> > M;
void print(int now){
	vector<int> rest;
	while(now!=m+1){
		rest.PB(now);
		now=las[now];
	}
	reverse(ALL(rest));
	cout<<rest.size()<<endl;
	for(auto it:rest){
		cout<<it<<' ';
	}
	cout<<endl;
}
int main(){
	SRAND;
	se=random(1000000)+233;
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		unsigned LL hs=0;
		rb(j,1,m){
			scanf("%d",&a[i][j]);
			hs^=Hs(a[i][j],j);
		}
		M[hs].push(i);
	}
	rb(i,1,n){
		unsigned LL hs=0;
		rb(j,1,m){
			scanf("%d",&b[i][j]);
			hs^=Hs(b[i][j],j);
		}
		if(M.find(hs)==M.end()){
			cout<<-1<<endl;
			return 0;
		}
		b[i][m+1]=M[hs].front();
		M[hs].pop();
		if(M[hs].empty()) M.erase(hs);
	}
	assert(M.empty());
	rb(i,1,m+1){
		rb(j,2,n){
			if(b[j][i]<b[j-1][i]){
				A[i].set(j-1);
			}
			if(b[j][i]!=b[j-1][i]){
				B[i].set(j-1);
			}
		}
	}
	int pre=0;
	int z=0;
	BS now;
	rb(i,1,m+1){
		if(A[i].count()==0){
			las[i]=pre;
			vis[i]=1;
			now|=B[i];
			if(pre==0) z=i;
			pre=i;
		}
	}
	if(!pre){
		cout<<-1<<endl;
		return 0;
	}
	rb(i,1,m){
		if(vis[m+1]) break;
		rb(j,1,m+1){
			if(!vis[j]&&(A[j]&now).count()==A[j].count()){
				las[z]=j;
				z=j;
				vis[j]=1;
				now|=B[j];
			}
		}
	}
	if(!vis[m+1]){
		cout<<-1<<endl;
	}
	else{
		print(pre);	
	}
	return 0;
}