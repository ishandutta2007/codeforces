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

int main(){
	vector<int> v;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a+b+c+d==0){
		puts("YES");
		return 0;
	}
	if(a+b+c+d==1){
		puts("YES");
		if(a){
			cout<<0;
		}
		else{
			if(b){
				cout<<1;
			}
			else{
				if(c){
					cout<<2; 
				}
				else{
					cout<<3;
				}
			}
		}
		return 0;
	}
	if(d+c==0){
		if(a-b==1){
			cout<<"YES"<<endl;
			cout<<"0 ";
			rb(i,1,b){
				cout<<"1 0 ";
			}
			return 0;
		}
	}
	if(a+b==0){
		if(d-c==1){
			cout<<"YES"<<endl;
			cout<<"3 ";
			rb(i,1,c){
				cout<<"2 3 ";
			}
			return 0;
		}
	}
	if(b<a||c<d){
		puts("NO");
		return 0;
	}
	b-=a,c-=d;
	if(abs(b-c)>1){
		puts("NO");
		return 0;
	}
	printf("YES\n");
	if(b>c){
		printf("1 ");
	}
	rb(i,1,a){
		printf("0 1 ");
	}
	rb(i,1,min(b,c)){
		printf("2 1 ");
	}
	rb(i,1,d){
		printf("2 3 ");
	}
	if(b<c){
		printf("2 ");
	}
	return 0;
}