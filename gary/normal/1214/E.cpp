//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[200000+10];
mp/*val,index*/ d[100000+10];
bool cmp(mp A,mp B){return A>B;}
int line[200000+10];
int t=1,h=1;
int main(){
	int n;
	cin>>n;
	rb(i,1,n) scanf("%d",&d[i].FIR),d[i].SEC=i+i-1;
	sort(d+1,d+1+n,cmp);
	rb(i,2,n){
		int u=d[i].SEC,v=d[i-1].SEC;
		each[v].PB(u);
//		cout<<i<<endl;
	} 
	rb(i,1,n){
		line[i]=d[i].SEC; 
	}
	t=n;
	h=0;
	rb(i,1,n){
		h++;
		if(t-h<d[i].FIR){
			line[++t]=d[i].SEC+1;
			each[line[t-1]].PB(d[i].SEC+1);
//			cout<<line[]
		}
		else{
			each[line[h+d[i].FIR-1]].PB(d[i].SEC+1);
//			cout<<"d"<<endl;
		}
	}
	rb(i,1,n+n){
		for(auto j:each[i]) printf("%d %d\n",i,j);
	}
	return 0;
}