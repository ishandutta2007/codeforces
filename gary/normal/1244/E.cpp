/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,a[100000+10],max_val=-INF,min_val=INF;
map<int,int> cnt;
LL k=0;
vector<mp> Tmp1,Tmp2;
int main(){
	cin>>n;
	cin>>k;
	rb(i,1,n) scanf("%d",&a[i]),max_val=max(max_val,a[i]),min_val=min(min_val,a[i]),cnt[a[i]]++;
	map<int,int> :: IT ite;
	int sum=0;
	for(ite=cnt.begin();ite!=cnt.end();ite++){
		sum+=ite->SEC;
		Tmp1.PB(II(ite->FIR,sum));
	} 
	sum=0;
	ite--;
	for(;;ite--){
		sum+=ite->SEC;
		Tmp2.PB(II(ite->FIR,sum));
		if(ite==cnt.begin()) break;
	}
	reverse(ALL(Tmp2));
	int p1,p2;
	p1=0,p2=Tmp1.size()-1;
	while(min_val<max_val){
//		cout<<p1<<" "<<p2<<endl;
		if(p1>p2) break;
//		cout<<p1<<" "<<p2<<" "<<Tmp1[p1].SEC<<" "<<Tmp2[p2].SEC<<" "<<Tmp2[p2].FIR<<endl;
		if(Tmp1[p1].SEC<Tmp2[p2].SEC){
			if(p1==Tmp1.size()-1){
				break;
			}
			else{
				LL Need=min(Tmp1[p1+1].FIR-Tmp1[p1].FIR,max_val-min_val);
				Need=min(Need,k/Tmp1[p1].SEC);
				k-=Need*Tmp1[p1].SEC;
				min_val+=Need;
				if(min_val!=Tmp1[p1+1].FIR) break;
				p1++;
			}
		}
		else{
			if(p2==0) break;
			else{
				LL Need=min(Tmp2[p2].FIR-Tmp2[p2-1].FIR,max_val-min_val);
				Need=min(Need,k/Tmp2[p2].SEC);
				k-=Need*Tmp2[p2].SEC;
				max_val-=Need;
				if(max_val!=Tmp2[p2-1].FIR) break;
				p2--;
			}	
		}
	}
//	cout<<min_val<<" "<<max_val<<endl;
	cout<<max_val-min_val;
	return 0;
}