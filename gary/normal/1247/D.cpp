/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
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
int cnt[100000+10],n,k,a[100000+10],change[100000+10],need[100000+10],cnt2[100000+10];
vector<int> each[100000+10];
int main(){
	cin>>n>>k;
	rb(i,1,n) scanf("%d",&a[i]),cnt[a[i]]++;
	rb(i,1,n)
	for(int j=1;j*j<=a[i];j++)
	if(a[i]%j==0){
	//	cout<<i<<"::"<<j<<" "<<a[i]/j<<endl;
		if(j!=1) each[i].PB(j);
		if((a[i]/j)!=1){
			each[i].PB(a[i]/j);
		}
	}
	rb(i,1,n) sort(ALL(each[i]));
	rb(i,1,n)
	{
		int cnt=0,tmp=a[i];
//		cout<<i<<":  ";
		change[i]=need[i]=1;
		for(auto it :each[i]){
//			cout<<","<<it<<" ";
			cnt=0;
			while(tmp%it==0){
				tmp/=it;
				cnt++;
			}
			cnt%=k;
			rb(j,1,cnt) change[i]*=it;
			if(need[i]!=INF)
			rb(j,1,(k-cnt)%k) {
				if(100000/it<need[i]){
					need[i]=INF;
					break;
				}
				need[i]*=it;
				
			}
		}//cout<<endl;
	}
	rb(i,1,n) cnt2[change[i]]++; 
//	rb(i,1,//n){
//		cout<<change[i]<<" "<<need[i]<<endl;
//	}
	LL res=0;
	rb(i,1,n){
		if(need[i]==change[i]){
			res+=cnt2[change[i]]-1;
		}
		else{
			if(need[i]!=INF)
			res+=cnt2[need[i]];
		}
//		cout<<"#"<<i<<" "<<res<<endl;
	} 
	cout<<res/2<<endl;
	return 0;
}