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
int main(){
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		if(num<19900){
			printf("133");
			rb(i,1,num){
				printf("7");
			}
		}
		else{
//			cout<<"OK"<<endl;
			int num2=0;
			while(1){	
				if(num%79800==0){
					break;
				}
				num2++;
				num--;
			}
			printf("133");
			rb(i,1,num2){
				printf("7");
			}
			rb(i,1,398){
				printf("3");
			}
			num/=79800;
			rb(i,1,num){
				printf("7");
			}
			
		}
		printf("\n");
	}
	return 0;
}