//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[100000+10];
int  a[300000+10],b[300000+10],degree[100000+10];
int one[100000+10],two[100000+10];
int main(){
	int n,m;
	cin>>n>>m;
	rb(i,1,m){
		scanf("%d %d",&a[i],&b[i]);
		each[a[i]].PB(b[i]);
		each[b[i]].PB(a[i]);
		degree[a[i]]++;
		degree[b[i]]++;
	} 
	for(auto it:each[1]) one[it]=-1;
	rb(i,1,n){
		if(one[i]==-1) one[i]=0; else one[i]=1;
	}	
	int tot1=0; 
	rb(i,1,n){
		if(one[i]){
			tot1++;
			if(degree[i]!=degree[1]){
				puts("-1");
				return 0;
			}
		}
	}
	rb(i,1,m){
		if(one[a[i]]&&one[b[i]]){
			puts("-1");
			return 0;
		}
	}
	int st=-1;
	rb(i,1,n){
		if(!one[i]) {
			st=i;
			break;
		}
	}
	if(st!=-1){
		for(auto it:each[st]){
			two[it]=-1;
		}
		int tot2=0;
		rb(i,1,n) {
			if(two[i]==-1) two[i]=0;
			else {
			two[i]=1;tot2++;
			}
		}
		rb(i,1,n){
			if(two[i]){
				if(degree[i]!=n-tot2){
					puts("-1");
					return 0;
				}
				if(degree[i]!=degree[st]){
					puts("-1");
					return 0;
				}
			}
		}
		rb(i,1,m){
			if((!two[a[i]]&&!two[b[i]])&&(!one[a[i]]&&!one[b[i]])){
				puts("-1");
					return 0;
			}
			if(two[a[i]]&&two[b[i]]){
				puts("-1");
				return 0; 
			}
		}
		rb(i,1,n){
			if(!two[i]&&!one[i]){
				if(degree[i]!=tot1+tot2){
					puts("-1");
					return 0;
				}
			}
		}
		
	} 
	else{
		puts("-1");
		return 0;
	}
	int OK1,OK2,OK3;
	OK1=OK2=OK3=0;
	rb(i,1,n){
		if(one[i]){
			OK1=1;
		}
		else{
			if(two[i])
				OK2=1;
			else 
				OK3=1;
		}
	}
	if(OK1&&OK2&&OK3);
	else{
		puts("-1");
		return 0;
	}
	rb(i,1,n){
		if(one[i]){
			printf("1 ");
		}
		else{
			if(two[i])
				printf("2 ");
			else 
				printf("3 ");
		}
	} 
	return 0;
}