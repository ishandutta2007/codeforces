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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[100000+10];
int flag=0;
//int flag2=0;
int tot=0;
int max_[100000+10];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		scanf("%d",&a[i]); 
		tot+=a[i];
		if(tot>m){
			puts("-1");
			return 0;
		}
		if(a[i]==0)flag=1;
	}
	rl(i,n,1){
		max_[i]=max(max_[i+1]+a[i],0);
		
	}
	if(flag){
		tot=0;
		int res=0;
		rb(i,1,n){
			tot+=a[i];
//			cout<<tot<<endl;
			if(a[i+1]==0&&i!=n){
				if(tot>=0){
					continue;
				}
				else{
					if(m-max_[i+1]<0){
//						cout<<i<<endl;
						puts("-1");
						return 0;
					}
					else{
						tot=m-max_[i+1];
						res++;
					}
				}
			}
			
		}
		cout<<res<<endl;
	}
	else{
		puts("0");
	}
	return 0;
}